#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int N=25;
int n,m;
int ma[N][N];
bool sb[N];
int sbcost=INF;
void dfs(int cur, int cost, int count){
	if(cost>=sbcost) return;
	if(count==n){
		if(ma[cur][0] !=INF){
			sbcost=min(sbcost,ma[cur][0]+cost);
		}
		return;
	}
	for(int city=0;city<n;city++){
		if(!sb[city] && ma[cur][city]!=INF){
			int big=ma[cur][city];
			if(cost+big >= sbcost) continue;
			sb[city] =true;
			dfs(city,cost+big,count+1);
			sb[city]=false; 
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	memset(ma,0x3f,sizeof(ma));
	for(int i=0;i<N;++i) ma[i][i]=0;
	cin >> n >>m;
	for(int i=0;i<m;i++){
		int u,v,big;
		cin >> u >>v >>big;
		u--,v--;
		ma[u][v]=min(ma[u][v],big);
		ma[v][u]=min(ma[v][u],big);
	}
	sb[0]=true;
	dfs(0,0,1);
	cout << sbcost << endl;
	return 0;
}
