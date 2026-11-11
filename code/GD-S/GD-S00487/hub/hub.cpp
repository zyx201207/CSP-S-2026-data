#include<bits/stdc++.h>
using namespace std;
int cc,t,n,k,l,r,u,v,d[1000005],mi,x,y;
vector<int> a[1000005];
int dfs(int x,int y,int u,int fa){
	if(x==u)return x;
	for(auto v:a[u])
	{
		if(v==fa)continue;
		dfs(x,y,v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cc>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if(n<=20){
			mi=n;
			for(int i=0;i<(1<<n);i++)
			{
				y=0;
				for(int j=0;j<n;j++)
				{
					if(i&(1<<j))y++;
				}
				if(y>k)continue;
				for(int j=0;j<n;j++)
				{
					if(!(i&(1<<j))){
						y=n;
						for(int l=0;l<n;l++)
						{
							if(i&(1<<l))y=min(dfs(l+1,j+1,1,0),y);
						}
						x=max(x,y);
					}
				}
				mi=min(mi,x);
			}
			cout<<mi<<"\n";continue;
		}
	    cout<<n-k<<"\n";
	}
	return 0;
}
