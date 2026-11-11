//GZ-S00193 »ÆÈË÷ë 
#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q,a[N][N],t[N][N],dist[N][M],w[N];
bool find(vector<int> vec,int x){
	for(int i:vec) if(i==x) return 1;
	return 0;
}
vector<int> sub[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) dist[i][j]=1e9;
	}
	for(int i=1;i<=m;i++){
		cin>>dist[0][i];
		dist[i][0]=dist[0][i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			sub[i].push_back(a[i][k]);
			if(j==1) continue;
			dist[a[i][j]][a[i][j-1]]=0,dist[a[i][j-1]][a[i][j]]=0;
			if(find(sub[i-1],a[i][k])){
				for(int u:sub[i]) dist[u][a[i][k]]=t[i][k],dist[a[i][k]][u]=t[i][k];
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++) dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
		}
	}
	while(q--){
		int s,e;cin>>s>>e;
		cout<<dist[0][s]+dist[s][e]+dist[e][0]<<"\n"; 
	} 
	return 0;
}
