#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],ans,cnt;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-m;i++){
		cnt=a[i];
		for(int j=1;j<m;j++){
			cnt=cnt & a[i+j];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
