#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool f[300005];
int x[500005];
int cnt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		memset(x,0,sizeof(x));
		int h=i;
		for(int j=i;j<=n;j++)
		{

			if(f[a[j]])
			{

				while(x[h]!=a[j]&&h>=1)
				{
					f[a[h]]=0;
					h--;
				}
				x[h++]=a[j];
				f[a[j]]=1;
			}
			else
			{

				f[a[j]]=1;
				x[h++]=a[j];
			}
		}
		for(int j=1;j<h;j++)
		{
			cnt[x[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}

