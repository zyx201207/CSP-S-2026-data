#include<bits/stdc++.h>
using namespace std;
int qwe,n,m,du,t,a[510],p[510],q[510],g[510][510];
vector<int>ve1[1010][510],ve2[1010][510];
void bfs(int r){
	queue<int>qu1,qu2;
	int b[510]={};
	for(int i=1;i<=m;i++){
		for(int j=0;j<ve1[i][r].size();j++){
			if(!b[ve1[i][r][j]]){
				qu1.push(ve1[i][r][j]);
				qu2.push(ve2[i][r][j]);
				b[ve1[i][r][j]]++;
			}
		}
	}
	b[r]++;
	while(!qu1.empty()){
		int u=qu1.front(),w=qu2.front();
		g[r][u]=min(g[r][u],w);
		qu1.pop(),qu2.pop();
		for(int i=1;i<=m;i++){
			for(int j=0;j<ve1[i][u].size();j++){
				if(!b[ve1[i][u][j]]){
					qu1.push(ve1[i][u][j]);
					qu2.push(ve2[i][u][j]);	
					b[ve1[i][u][j]]++;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>qwe>>m>>n>>du>>t;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=1e9; 
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int len=0;
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>q[j]>>p[j];
			for(int k=1;k<j;k++){
				int w=p[k]+p[j],u=q[j],v=q[k];
				ve1[i][u].push_back(v);
				ve2[i][u].push_back(w);
				ve1[i][v].push_back(u);
				ve2[i][v].push_back(w);
			}
		}
	}
	for(int i=1;i<=n;i++)bfs(i);
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<+n;j++){
				if(i!=k&&j!=k&&i!=j)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<a[x]+a[y]+g[x][y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
