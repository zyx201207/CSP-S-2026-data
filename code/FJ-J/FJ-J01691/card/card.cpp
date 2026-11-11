#include<bits/stdc++.h>
using namespace std;
#define int long 
#define INF 0x3f3f3f3f3f3f3f3f3f3f
#define endl '\n'
int n,m;
int a[300010];
int b[300010];
bool v[300010];
signed main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		int fs=1;
		for(int j=1;j<=n;j++)
		{
			int c[300010];
			memset(c,0,sizeof(c));
			for(int k=j;k<=n;k++)
			{
				c[k]=a[k];
			}
			
			for(int k=j;k<=n;k++)
			{
				int cnt=c[k];
				bool bo=true;
				int ab=0;
				for(int l=1;l<=n;l++)
				{
					if(b[i]==cnt)
					{
						bo=false;
						ab=i;
						break;
					}
				}
				if(bo==false)
				{
					for(int l=ab;l<=n;l++)
					{
						b[l]=0;
						v[l]=true;
					}
					if(v[ab+1]==false)
					{
						b[ab+1]=cnt;
						fs=ab+1;
						if(cnt==i)
						{
							ans++;
						}
					}
				}
				else
				{
					if(v[k]==false)
					{
						b[fs]=cnt;
						if(cnt==i)
						{
							ans++;
						}
						fs++;
					}
					
				}
			}
			memset(b,0,sizeof(b));
			fs=1;
		}
		cout<<ans<<" ";
		
	}
	return 0;
}
