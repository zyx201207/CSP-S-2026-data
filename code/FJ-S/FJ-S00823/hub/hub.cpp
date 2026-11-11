#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=510;
int dian,n,m,d,q,w[N],head[N+M],tot,a[M][M];
struct node {
	int ed,val,nxt;
} edge[N+M];
void add(int u,int v,int w) {
	edge[++tot]={v,w,head[u]};
	head[u]=tot;
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(NULL)->sync_with_stdio(false);
	return 0;
}
