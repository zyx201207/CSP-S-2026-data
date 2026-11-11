#include<bits/stdc++.h>
#define il inline
#define int long long
#define pii pair<int,int>

using namespace std;
const int maxn=2e6+5;
int n,m,a[maxn],ans,c;
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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	c=read();
	int t=read();
	while(t--)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=1;i<n-2;i++)
			for(int j=i+1;j<n-1;j++)
				if(a[j]-a[i]<=m)
					for(int p=j+1;p<n;p++)
						if(a[p]-a[j]<=m)
							for(int q=p+1;q<=n;q++)
								if(a[q]-a[j]<=m)
								{
									if(a[q]-a[i]>m)
										ans++;
								}
								else
									break;
						else
							break;
				else
					break;
		printf("%lld\n",ans);
	}
	return 0;
}

