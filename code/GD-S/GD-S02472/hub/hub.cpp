#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
vector<int> g[N];
struct node{
	int u, v, w;
	bool operator<(node b){
		return w<b.w;
	} 
};
node e[N];
int n, m, t, ans;
void minrd(int x, int y, int cnt){
	if(x == y){
		ans = min(ans, cnt);
		return;
	}
	if(cnt > ans) return;
	for(auto i:g[x]){
		minrd(i,y,cnt+1); 
	}
}
int fa[N]; 
int find

int main(){
	cin.tie(0)->sync_with_stdio(false);
	cin>>t>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			int u, v;
			g[u].push_back(v);
			e[i].u = u;
			e[i].v = v;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans = 0;
				minrd(j,i,0);
				for(int i=1;i<=n;i++){
					if(e[i].u == j and e[i].v == i) {
						e[i].w = ans;
					}
				}
			}
		}
		for(int )
		sort(e,e+n+1);
		int cnt = 0, sum = 0;
		queue<int> q;
		cout<<"114514";
	}
	return 0;
}
