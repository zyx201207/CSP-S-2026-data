#include<bits/stdc++.h>
using namespace std;
const long long E=1e18;
long long x,y,n,m,w[2505010],q,c,d;
long long W[10010][10010],a[510][510],t[510][510];
vector<long long>v[2505010];
bool p[2505010];
void dfs(int x,int f,int g){
	for(int i=0;i<v[x].size();i++){
		if(v[x][i]!=f and !p[v[x][i]]){
			p[v[x][i]]=1;
			if(W[g][v[x][i]]==E){
				W[g][v[x][i]]=W[g][x]+W[x][v[x][i]];
			}else{
				W[g][v[x][i]]=min(W[g][v[x][i]],W[g][x]+W[x][v[x][i]]);
			}
			dfs(v[x][i],x,g);
			p[v[x][i]]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			W[i][j]=E;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		a[i][0]=k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			for(int h=1;h<j;h++){
				v[a[i][j]].push_back(a[i][h]);
				v[a[i][h]].push_back(a[i][j]);
				W[a[i][j]][a[i][h]]=W[a[i][h]][a[i][j]]=t[i][a[i][j]]+t[i][a[i][h]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		dfs(i,i,i);
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<W[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		cin>>x>>y;
		cout<<W[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2
*/
