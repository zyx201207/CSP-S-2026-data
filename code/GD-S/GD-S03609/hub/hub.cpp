#include<bits/stdc++.h>
#define N 1000010
#define M (1<<15)+10
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define lowbit(x) (x&-x)
namespace graph{
	int head[N],nxt[N<<1],to[N<<1],cnt_edge;
	void connect(int x,int y){
		++cnt_edge;
		nxt[cnt_edge] = head[x],to[cnt_edge] = y,head[x] = cnt_edge;
	}
}using namespace graph;
using namespace std;
int _,T,n,k;
int mpe[M];// countbit 
int q[N],*front,*tail;
bool s[N];
int dst[N];
int fa[N],cnt;// dsu
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
} 
void merge(int x,int y){
	x = find(x),y = find(y);
	if(x == y)return ;
	--cnt;fa[x] = y;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin >> _ >> T;
	for(int i = 1;i < M;++i)mpe[i] = mpe[i>>1] + (i&1);
	while(T--){
		cin >> n >> k;
		cnt_edge = 0;
		for(int i = 1;i <= n;++i)head[i] = 0;
		for(int i = 1;i < n;++i){
			int u,v;cin >> u >> v;
			connect(u,v),connect(v,u);
		}
		int ans = INF;
		for(int S = 0;S < (1<<n);++S){
			if(mpe[S] != k)continue;
			front = tail = q;
			cnt = n;
			for(int i = 1;i <= n;++i)fa[i] = i;
			for(int i = 1;i <= n;++i){
				s[i] = ((1<<i-1) & S);
				if(s[i]){
					dst[i] = 0,*(tail++) = i;
					for(int edg = head[i];edg;edg = nxt[edg]){
						if(s[to[edg]])merge(i,to[edg]);
					}
				}
				else dst[i] = INF;
			}
			if(cnt != n-k+1 && cnt != n-k+2)continue;
			while(front != tail){int x = *(front++);
				for(int edg = head[x];edg;edg = nxt[edg]){
					int v = to[edg];
					if(dst[v] <= dst[x] + 1)continue;
					dst[v] = dst[x] + 1;*(tail++) = v;
				}
			}
			int bos = 0;
			for(int i = 1;i <= n;++i)bos = max(bos,dst[i]);
			ans = min(ans,bos);
		}
		cout << ans << '\n';
	}
	
	
	return 0;
} 
