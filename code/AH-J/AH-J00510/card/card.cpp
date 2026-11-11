#include <bits/stdc++.h>
using namespace std;
struct cp
{
	int x,y;
}t[250005];
int a[500005],f[500005],o[300005],b[300005],c[500005],n,m,k;
bool cmp(cp s1,cp s2)
{
	if(s1.y!=s2.y)
	{
		return s1.y<s2.y;
	}
	return s1.x<s2.x
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(f[a[i]]==0)
		{
			o[a[i]]++;
			for(int j=n;j>i;j--)
			{
				if(b[a[j]]==1)
				{
					o[a[j]]++;
				}
			}
			b[a[i]]=1;
			continue;
		}
		for(int j=i;j<=n;j++)
		{
			c[j]=0;
		}
		k=0;
		for(int j=i;j<=n;j++)
		{
			for(int l=j+1;l<=n;l++)
			{
				if(a[j]==a[l])
				{
					k++;
					t[k].x=j;
					t[k].y=l;
				}
			}
		}
		sort(t+1,t+k+1,cmp);
		for(int j=1;j<=k;j++)
		{
			if(c[t[j].x]==0)
			{
				for(int l=t[j].x;l<=t[j].y;l++)
				{
					c[l]=1;
				}
				c[t[j].y]=0;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(c[j]==0)
			{
				b[a[j]]=1;
			}
		}
		f[a[i]]=1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<o[i]<<" ";
	}
}
