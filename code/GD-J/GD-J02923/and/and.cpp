#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000001],f[1000001],ans,cnt,sum,ma,u;
void dfs(int i,int sum){
	if(i>m){
		ans=max(ans,sum);
		return;
	}
	else{
		for(int j=1;j<=n;j++){
			if(f[j]==1) continue;
			f[j]=1;
			if(sum==0) dfs(i+1,a[j]);
			else dfs(i+1,sum&a[j]);
			f[j]=0;
		}
	}
}
main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
		u=(u&a[i]);
	}
	if(m==n) cout<<u,exit(0);
	if(m==1){
		cout<<ma;
		exit(0);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
