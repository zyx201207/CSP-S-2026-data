#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],pre[500005],n,m,ans;
inline bool check(int x){
	for(int i=1,j=x;j<=n;++i,++j)
	if((x*a[j]-(pre[j]-pre[i-1]))<=m){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n,less<int>());
	int k=a[1];
	for(int i=1;i<=n;++i)a[i]-=k;
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	int l=1,r=n,ans;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	//cerr<<ans;
	return 0;
}
