#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans,dis[2000005],vis[2000005],h[2000005];
void dfs(long long k,long long s){
	vis[k]=1;
	if(s==h[k])dis[k]++;
	else if(s<h[k])h[k]=s,dis[k]=1;
	else{
		vis[k]=0;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]||abs(x[k]-x[i])>d)continue;
		dfs(i,s+1);
	}
	vis[k]=0;
	return ;
}
void ss(){
	for(int i=1;i<=n;i++){
		memset(dis,0,sizeof dis);
		memset(h,0x3f,sizeof h);
		dfs(i,0);
		for(int j=i+1;j<=n;j++){
			if(j==i)continue;
			if(dis[j]==2)ans++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=5000){
			ss();
			cout<<ans<<"\n";
		}else{
			
		}
	}
	return 0;
}
