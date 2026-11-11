#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<long long> w(m+5);
	vector<vector<long long>> dist(m+n+5,vector<long long>(m+n+5,1e18));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=m+1;i<=n+m;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			dist[i][x]=y;
			dist[x][i]=y;
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dist[x][y]<<endl;
	}
 } 
