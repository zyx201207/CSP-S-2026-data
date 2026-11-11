#include<bits/stdc++.h>
using namespace std;
int fa[15],g[15][15];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)
		  if(i==j)g[i][j]=0;
		  else g[i][j]=1e9;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u][v]=g[v][u]=1;
		}
		int mi=INT_MAX;
		for(int i=0;i<(1<<n);i++){
			vector<int> v;int mx=0,cnt=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					cnt++;
					v.push_back(j+1);
				}
			}
			if(cnt!=k)continue;
			for(int i=0;i<v.size();i++)fa[i]=i;
			cnt=0;
			for(int i=0;i<v.size();i++)
		         for(int j=i+1;j<v.size();j++)
		          if(g[v[i]][v[j]]==1)
		           fa[find(i)]=find(j);
			
		    for(int i=0;i<v.size();i++)
		     cnt+=(fa[i]==i);
            if(cnt>2)continue;
            for(int k=1;k<=n;k++)
             for(int i=1;i<=n;i++)
              for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                
            for(int i=1,x;i<=n;i++){
            	x=1e9;
                for(int j=0;j<v.size();j++){
                	x=min(x,g[i][v[j]]);
                }
                mx=max(mx,x);
             }
            mi=min(mx,mi);
		}
		cout<<mi<<"\n";
	}
}




