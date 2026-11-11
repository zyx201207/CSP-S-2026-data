#include<bits/sdtc++.h>
#define int long long
using namespace std;
const int N = 1e4+10;
int dist[N],vis[N];
struct node{
	int x;
};
void bfs(int x,int y){
	queue<node> q;
	q.push(x);
	vis[x] = 1;
	dist[x] = 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
	}
	return 0;
}
