#include <iostream>
#include <queue> 
#include <cstring>
using namespace std;
typedef long long ll;
const ll M = 5e5 + 10,N = 500 + 10;
struct Node {ll u,d;};
ll w[M]; ll a[N][M],t[N][M];
ll c,n,m,d,Q;
void bfs()
{ 
	queue<Node> q;
	q.push({1,0});
	while(!q.empty())
	{
		ll u = q.front().u;
		ll d = q.front().d; q.pop();
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i ++)scanf("%lld",w + i);
	for(ll i = 1,k;i <= n;i ++)
	{
		scanf("%lld",&k);
		for(int j = 1;j <= k;j ++)
		scanf("%lld%lld",&a[i][j],&t[i][j]);
	}
	while(Q --)
	{
		ll st,ed;
		scanf("%lld%lld",&st,&ed);
		printf("%lld\n",w[st] + w[ed] + 12);
	}
	return 0;
} 
