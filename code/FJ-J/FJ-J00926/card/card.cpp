#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[5931809],b[8956321],c[4832975];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				b[a[j]]=j;
			}
			else
			{
				for(int k=b[a[j]];k<j;k++)
				{
					b[a[k]]=0;
				}
				b[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]!=0)
			{
				c[a[j]]++;
				b[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
