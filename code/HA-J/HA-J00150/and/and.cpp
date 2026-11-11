#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=2e5+10;
int maxn,a[N];
int cnt,ans;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1]&a[2];
	for(int i=3;i<=m;i++){
		ans&=a[i];
	}cout<<ans;
	return 0;
}

