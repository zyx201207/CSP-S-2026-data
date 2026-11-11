#include<bits/stdc++.h>
using namespace std;
int a[500005],c[300005];
bool b[300005];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool first=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]+=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[a[i]]==0) b[a[i]]=1;
		else b[a[i]]=0;
		if(b[a[i]]==0)
		{
			for(int j=i-1;;j--)
			{
				if(first)
				{
					if(j==1)
					{
						c[a[j]]-=n-i;
						break;
					}
				}
				else if(a[j]==a[i]&&b[a[j]]==0)
				{
					c[a[j]]-=n-i;
					break;
				}
				if(b[a[j]]==1) c[a[j]]-=n-i;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
