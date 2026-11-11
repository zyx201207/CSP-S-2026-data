#include<bits/stdc++.h>
#define int long long
#define il inline
#define pii pair<int,int>

using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
int n,m,lsa[maxn],las[maxm],ans[maxm],a[maxn],cfa[maxn],sum,dp[maxn];
il int read()
{
	int res,f=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')
		if(ch=='-')
			f=-1;
	res=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res*f;
}

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		lsa[i]=las[a[i]];
		las[a[i]]=i;
		ans[i]=i;
	}
	for(int i=1;i<=n;i++)
		if(lsa[i])
		{
			int j=i-1,p=lsa[i];
			while(j>p)
			{
				ans[j]-=ans[lsa[i]];
				if(lsa[j]<p)
					j--;
				else
					j=lsa[j];
			}
		}
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[las[i]]);
	putchar('\n');
	return 0;
}
