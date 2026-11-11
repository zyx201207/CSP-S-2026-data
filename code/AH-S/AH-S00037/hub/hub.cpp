#include<bits/stdc++.h>
using namespace std;
int d[1010][1010],c,T,n,k,ans=INT_MAX,f[1010],r[1010][1010],h[1010];
void dfs(int s,int t,int p,int l){
	if(p>=ans) return;
	if(s==k){
		ans=p;
		return;
	}
	if(t==n+1) return;
	int e=p;
	for(int i=1;i<=n;i++){
		h[i]=min(h[i],d[i][t]);
		e=max(e,h[i]);
	}
	int fl=0;
	for(int i=1;i<=n;i++){
		if(r[t][i]==1){
			if(f[i]){
				fl=1;
			}
		}
	}
	if(fl==1){
		f[t]=1;
		dfs(s+1,t+1,e,l);
		f[t]=0;
	}
	else{
		if(l+1<=2){
			f[t]=1;
			dfs(s+1,t+1,e,l+1);
			f[t]=0;
		}
	}
	dfs(s,t+1,p,l);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=INT_MAX;
		memset(h,0x3f,sizeof h);
		memset(d,0x3f,sizeof d);
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			d[u][v]=d[v][u]=1;
			d[i][i]=0;
			r[u][v]=r[v][u]=1;
		}
		d[n][n]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
				}
			}
		}
		dfs(0,1,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
