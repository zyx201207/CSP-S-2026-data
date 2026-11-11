#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
ifstream fin("subway.in");
ofstream fout("subway.out");
//#define debug
#ifndef debug
#define cin fin
#define cout fout
#endif
int c,n,m,d,q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	vector<ll>w(m);for(auto&i:w)cin>>i;
	vector<int>k(n);
	vector<vector<int>>a(n);
	vector<vector<ll>>t(n);
	vector<vector<ll>>locate(m);
	vector<vector<ll>>D(m,vector<ll>(m,ULONG_LONG_MAX));//邻接表
	//vector<vector<int>>reach(m);
	for(int i=0;i<n;i++)D[i][i]=0;
	for(int i=0;i<n;i++){
		cin>>k[i];
		a[i].resize(k[i]);
		t[i].resize(k[i]);
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];a[i][j]--;//cout<<j<<' '<<a[i][j]<<endl;
			locate[a[i][j]].push_back(i);
			for(int l=0;l<j;l++){
				int u=a[i][l],v=a[i][j];
				D[u][v]=D[v][u]=t[i][l]+t[i][j];
				//reach(u).push_back(v);
				//reach(v).push_back(u);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;x--;y--;
		vector<bool>visit(n,false);
		for(int i=0;i<m;i++)if(D[x][i]!=ULONG_LONG_MAX)visit[i]=true;
		queue<int>Q;Q.push(x);
		while(!Q.empty()){
			int t=Q.front();Q.pop();//t为站台 
			if(visit[t])continue;
			ll Min=ULONG_LONG_MAX;
			for(auto&i:locate[t])//i为线路 
				for(auto&j:a[i]){//j为该线路能到达的站台
					if(visit[j]){ 
						Min=min(Min,D[x][j]+D[j][t]);
					}else{
						Q.push(j);
					}
				}
			D[x][t]=D[t][x]=Min;
			visit[t]=true;
		}
		cout<<w[x]+D[x][y]+w[y]<<endl;
	}
	/*cout<<endl<<endl<<endl;
	for(int i=0;i<m;i++)cout<<w[i]<<'\t';cout<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++)
			cout<<(D[i][j]==ULONG_LONG_MAX?100:D[i][j])<<'\t';
		cout<<endl;
	}*/
}
