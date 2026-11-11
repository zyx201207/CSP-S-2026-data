#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500001],c,n,m,d,q;
unordered_map<int,int>mp[500010];
int p[500010][21],f[501][501];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j++){
			int x,l;
			cin>>x;
			if(j%2) p[x][++p[x][0]]=i;
			else mp[l][i]=x;
			l=x;
		}
	}
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++) 
	      f[i][j]=1e9;   
	for(int i=1;i<=n;i++) f[i][i]=0;  
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=p[i][0];j++)
	    for(int k=1;k<=p[i][0];k++)
	      if(j!=k){
	      	int g=mp[i][p[i][j]]+mp[i][p[i][k]];
	      	f[p[i][j]][p[i][k]]=f[p[i][k]][p[i][j]]=g;
		  }
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
	   		for(int j=1;j<=n;j++)
	        f[i][j]=min(f[i][k]+f[k][j],f[i][j]);   		      
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e9;
		for(int i=1;i<=p[x][0];i++)
		   for(int j=1;j<=p[y][0];j++)
		      ans=min(ans,f[p[x][i]][p[y][j]]+mp[x][p[x][i]]+mp[y][p[y][j]]);
	    cout<<ans+w[x]+w[y]<<"\n";
	}
}
