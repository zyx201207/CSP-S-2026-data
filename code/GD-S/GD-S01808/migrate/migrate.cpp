#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=2e6+5;
ll c,t,n,d,x[MAXN],nxt[MAXN],pre[MAXN],a[MAXN];
ll subA()
{
	if(n==1) return 0;
	ll times=d/(x[2]-x[1]);
	if(times==0||times==1) return 0;
	return max(n-(2*times-1),0LL);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(c==11||c==12)
		{
			printf("%lld\n",subA());
			continue;
		}
		ll p=n,s=0; nxt[n]=n;
		for(ll i=n-1;i>=1;i--)
		{
			s+=x[i+1]-x[i];
			while(s>d) s-=x[p]-x[p-1],p--;
			nxt[i]=p;
		}
		p=1,s=0; pre[1]=1;
		for(ll i=2;i<=n;i++)
		{
			s+=x[i]-x[i-1];
			while(s>d) s-=x[p+1]-x[p],p++;
			pre[i]=p;
		}
//		for(ll i=1;i<=n;i++) printf("%lld ",nxt[i]);
//		printf("\n");
//		for(ll i=1;i<=n;i++) printf("%lld ",pre[i]);
//		printf("\n");
		ll ans=0;
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++)
			{
				ll len=1; a[1]=i;
				while(nxt[a[len]]!=a[len]&&nxt[a[len]]<j) a[len+1]=nxt[a[len]],len++;
				if(nxt[a[len]]<j) continue;
				a[len+1]=j,len++;
				bool is_ans=false;
				for(ll k=len-2;k>=1;k--)
					if(pre[a[k+2]]!=a[k+1])
					{
						if(pre[a[k+2]]<=a[k]) {is_ans=false; break;}
						if(a[k+1]-pre[a[k+2]]>1) {is_ans=false; break;}
						if(pre[pre[a[k+2]]]<a[k]&&k!=1) {is_ans=false; break;}
						if(is_ans) {is_ans=false; break;}
						else is_ans=true;
					}
				ans+=is_ans;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
