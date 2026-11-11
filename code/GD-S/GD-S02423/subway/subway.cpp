#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q,w[500005],k[505];
int dist[20005][20005];

vector<int> a[505],t[505];

int min(int a,int b){
	if(a<=b) return a;
	return b;
} 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;
			cin>>u>>v;
			a[i].push_back(u);
			t[i].push_back(v);
		}
	}
	for(int i=1;i<=m;i++) {
		dist[i][i]=0;
		for(int j=1;j<=m;j++){
			if(j==i) continue;
			dist[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i]-1;j++){
			for(int l=j+1;l<k[i];l++){
				int aj=a[i][j],al=a[i][l];
				dist[al][aj]=min(dist[al][aj],t[i][j]+t[i][l]);
				dist[aj][al]=min(dist[aj][al],t[i][j]+t[i][l]);
			}
		}
	}
	for(int l=1;l<=m;l++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(dist[i][j]>dist[i][l]+dist[l][j])
					dist[i][j]=dist[i][l]+dist[l][j];
					
	
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dist[u][v]+w[u]+w[v]<<endl;
	}
	return 0;
}
