//GZ-S00339 遵义市第四中学 周语函 
#include <bits/stdc++.h>
using namespace std;
struct No{
	int pos,step;
};
int c,t;
int n,d,x[1000005];
bool vis[1000005];
vector <int> vec;
queue <No> que; 
bool bfs(int u,int v){
	memset(vis,0,sizeof(vis));
	int mn = 2e9,num = 1;
	que.push({u,1});
	vis[u] = true;
	while(!que.empty()){
		No fr = que.front();
		que.pop();
		for(int i = 0 ; i < vec[fr.pos].size() ; i++){
			int nxt = vec[fr.pos][i];
			if(vis[nxt]) continue;
			vis[nxt] = true;
			if(fr.step+1 < mn){
				mn = fr.step+1;
				num = 1;
			}
			if(fr.step+1 == mn){
				num++;
			}
		}
	}
	if(num == 2)return true;
	else return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i++){
			cin >> x[i];
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				if(abs(x[i]-x[j]) <= d){
					vec[i].push_back(j);
				}else break;
			}
		}
		int ans = 0;
		for(int i = 1 ; i < n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				if(bfs(i,j)) ans++;
			}
		}
		cout << ans;
	}
	return 0;
}
