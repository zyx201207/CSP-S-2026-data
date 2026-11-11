#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],ans=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m-1;i++){
		ans=a[i]&a[i+1];
	}
	cout<<ans;
	return 0;
}
