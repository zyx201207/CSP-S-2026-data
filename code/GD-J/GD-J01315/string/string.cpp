#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll ans;
int n;
ll l[N],r[N],len[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>len[i]>>c[i];
		l[i]=r[i-1]+1ll;
		r[i]=l[i]+len[i]-1ll;
	}
	ans=r[n]/2ll;
	for(int i=1,j=n;i<=n;i++)
	{
		ll tl=r[n]-min(r[i],r[n]/2ll)+1ll;
		ll tr=r[n]-l[i]+1ll;
		if(tl>tr) break;
		while(tr<l[j]) j--;
		for(;j>=0&&r[j]>=tl;j--)
		{
			if(c[j]==c[i])
			{
				ans-=min(tr,r[j])-max(tl,l[j])+1ll;
			}
		}
		j++;
		if(tr==(r[n]/2ll)) break;
	}
	printf("%lld",ans);
	return 0;
}
