#include<bits/stdc++.h>
using namespace std;
long long gs,T,n,m,a[1010011],op[11001],ans;
void dfs(long long j,long long x,long long h){
	if(abs(op[j])>h) op[j]=h;
	else if(op[j]==h) op[j]=-h;
	else if(op[j]==-h){
		op[j]=0;
		return ;
	}
	for(long long i=j+1;i<=n;i++){
		if(a[i]-a[j]<=m) dfs(i,a[i],h+1);
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>gs>>T;
	while(T--){
		cin>>n>>m;
		for(long long i=1;i<=n;i++) cin>>a[i];
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++) op[j]=1e18;
			dfs(i,a[i],1ll);
			for(long long j=i+1;j<=n;j++) if(op[j]<0) ans++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}/*
0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000*/

