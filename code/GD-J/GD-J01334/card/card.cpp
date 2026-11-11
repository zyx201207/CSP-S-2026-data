#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],b[500010],len[500010],v[500010],ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n<=5000)
	{
		for(ll k=1;k<=n;k++)
		{
			ll cnt=0;
			memset(v,0,sizeof v);memset(len,0,sizeof len);
			for(ll i=k;i<=n;i++)
			{
				len[++cnt]=a[i];
				if(v[a[i]])
				{
					len[cnt]=0;
					cnt--;
					for(ll j=cnt;j;j--)
					{
						if(len[j]==a[i])break;
						v[len[j]]=0;len[j]=0;cnt--;
					}
				}
				v[a[i]]=1;
			}
			for(ll i=1;i<=cnt;i++)ans[len[i]]++;
		}
		for(ll i=1;i<=m;i++)printf("%lld ",ans[i]);
	}
	else for(ll i=1;i<=m;i++)printf("%lld ",i);
	return 0;
}
