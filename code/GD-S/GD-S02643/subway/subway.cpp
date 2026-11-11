#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500005],a,t,s[505][505],u,v,ans=1e18,x,y,t1,t2;
struct P{
	int a,t;
};
vector<P>e[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			e[a].push_back({i,t});
		}
		
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)
			s[i][j]=1e18;
		}
	}
	
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int k=0;k<e[i].size();k++){
				if(j==k)
				continue;
				u=e[i][j].a,v=e[i][k].a,t1=e[i][j].t,t2=e[i][k].t;
				s[u][v]=s[v][u]=min(s[u][v],t1+t2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||j==k||i==k)
				continue;
				s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	}
	
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[y].size();j++){
				ans=min(ans,s[e[x][i].a][e[y][j].a]+e[x][i].t+e[y][j].t);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

