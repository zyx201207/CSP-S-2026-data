#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
bool f[300005];
long long cnt[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(f[a[i]]==1)
			{
				int p;
				for(int x=1;x<=n;x++)
				{
					if(x==i)
					{
						p=x;
						break;
					}	
				}
				for(int x=p;x<=n;x++)
				{
					b[x]=0;
					l--;
				}
				b[l++]=a[i];
			}
			else
				b[l++]=a[i];
		}
		for(int j=1;j<=l;)
			cnt[b[i]]++;
	}
	for(int i=1;i<=n;i++)
		cout<<cnt[i]<<" ";
	return 0;
}  
