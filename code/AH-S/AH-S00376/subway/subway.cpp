#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long v,w;
	bool operator <(const node &rhs)const
	{
		return w > rhs.w;
	}
}
long long C,n,m,d,q,x,y;
long long w[500010];
vector<node> G[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++)
		scanf("%lld",w + i);
	while(q --)
	{
		scanf("%lld%lld",&x,&y);
		cout << w[x] + w[y] << endl;
	}
	
	return 0;
}
