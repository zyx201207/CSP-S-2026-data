#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],dist[20005][20002],a[500005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dist[i][j]=1e9;
			if(i==j) dist[i][j] = 0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int h=1;h<=n;h++) 
			if(t[a[h]]+t[a[j]]<dist[a[h]][a[j]]) 
			dist[a[h]][a[j]]=t[a[h]]+t[a[j]];	
		}
	}

	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}
    while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dist[x][y]<<endl;
	}
	return 0;
}

