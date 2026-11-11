#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
ll ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		ll s[500005],k=0,p[500005];
		bool f[500005];
		memset(f,false,sizeof(f));
		for(ll j=i;j<=n;j++)
		{
			s[++k]=a[j];
			if(f[a[j]])
			{
				for(int q=p[s[k]];q<=k;q++)
				{
					f[a[j]]=false;
					s[q]=0;
				}
			}
			else
			{
				f[a[j]]=true;
				p[s[k]]=k;
			}
		}
		for(ll j=1;j<=k;j++)ans[s[j]]++;
	}
	for(ll i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
