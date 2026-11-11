#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long 
int a[500010];
int b[500010];
int c[500010];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1;
	int t=n;
	while(t--)
	{
		for(int i=l;i<=n;i++)
		{
			bool f=0;
			int s=0;
			int bb=0;
			for(int j=1;j<=n;j++)
			{
				if(a[i]==b[j])
				{
					f=1;
					s=j;
				}
			}
			if(f==1)
			{
				for(int j=s+1;j<=n;j++)
				{
					b[j]=0;
				}
				bb=s;
			}
			else
			{
				bb++;
				b[bb]=a[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			c[b[i]]++;
			b[i]=0;
		}
		l++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<"¡¡";
	}
	return 0;
}
