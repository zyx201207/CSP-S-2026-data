#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200000;
ll n,cnt=0,mid,pl,pr,pmid,ml,mr,ans=0,move;
struct part{
	ll a,l,r;
	char c;
}p[N+10];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld %c ",&p[i].a,&p[i].c);
		p[i].l=cnt+1;
		cnt+=p[i].a;
		p[i].r=cnt;
	}
	mid=mr=(cnt+1)>>1,ml=(cnt>>1)+1;
	pl=1,pr=n;
	while(pl<pr)
	{
		pmid=(pl+pr)>>1;
		if(p[pmid].r<mid)pl=pmid+1;
		else pr=pmid;
	}
	if(mr>p[pl].r)
	{
		pr=pl+1;
		if(p[pl].c!=p[pr].c)++ans;
	}
	while(pl>=1&&pr<=n)
	{
		move=min(ml-p[pl].l,p[pr].r-mr);
		if(p[pl].c!=p[pr].c)ans+=move;
		ml-=move,mr+=move;
		if(ml==p[pl].l)--pl;
		if(mr==p[pr].r)++pr;
	}
	printf("%lld",ans);
	return 0;
}
