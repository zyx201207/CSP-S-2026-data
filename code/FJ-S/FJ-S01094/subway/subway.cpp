#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int maxm = 500010;
const int inf = 0x3f3f3f3f;
int w[maxm],head[maxm],to[2 * maxm],nxt[2 * maxm];
bool vis[maxm];
int c,n,m,d,q,t;
struct node{
	int a,t;
}p[maxm];
int tot = 0;
void add(int x,int y){
	to[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	tot++;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	return 0;
}
