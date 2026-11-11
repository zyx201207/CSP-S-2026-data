#include<bits/stdc++.h>
using namespace std;
const int N = 5E2+5;
const int M = 1E5+5;
const int D = 25;
const int Q = 1E5+5;
int w[M],k[N],a[M],t[N][M];
int c,n,m,d,q,ans;
vector<int> e[N][M];
vector<int> l[M];
void dfs(int x,int way,int line,int tgt){
	if(x == tgt){
		ans = min(ans,way);
		return;
	}
	for(int i = 0;i < l[x].size();i++){
		for(int j = 0;j < e[l[x][i]][x].size();j++){
			if(line == l[x][i]){
				dfs(e[l[x][i]][x][j],way,l[x][i],tgt);
			}else{
				
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>k[i];
		cin>>a[1]>>t[i][1];
		l[a[1]].push_back(i);
		for(int j = 2;j <= k[i];j++){
			cin>>a[j]>>t[i][j];
			e[i][a[j]].push_back(a[j-1]);
			e[i][a[j-1]].push_back(a[j]);
			l[a[j]].push_back(i);
		}
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		cin>>x>>y;
		ans = INT_MAX;
		for(int i = 0;i < l[x].size();i++){
			dfs(x,t[l[x][i]][i],l[x][i],y);
		}
		ans += w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
