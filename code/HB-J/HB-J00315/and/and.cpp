#include<bits/stdc++.h>
using namespace std;
int n,m,x,c,y,b[200005],k[100],l,p=1,ans,ba;bool v;
vector<int> a[40];
int mi(int q)
{
	ba=1;
	for(int i=1;i<=q;i++)
	{
		ba*=2;
	}
	return ba;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;k[0]=32;
	for(int i=1;i<=n;i++)
	{
		cin>>x;y=x;
		c=0;
		while(x)
		{
			if(x/2*2!=x)
			{
				a[c].push_back(y);
			}
			c++;x/=2;
		}
	}
	while(1)
	{
		v=1;
		for(int i=k[p-1]-1;i>=0;i--)
		{
			if(int(a[i].size())>=m)
			{
				k[p]=i,l=int(a[i].size());
				v=0;
				break;
			}
		}
		if(v)
		{
			break;
		}
		for(int i=1;i<=l;i++)
		{
			b[i]=a[k[p]][i-1];
		}
		for(int i=0;i<=31;i++)a[i].clear();
		for(int i=1;i<=l;i++)
		{
			x=b[i];
			c=0;
			while(x)
			{
				if(x/2*2!=x)
				{
					a[c].push_back(b[i]);
				}
				c++;x/=2;
			}
		}
		p++;
	}
	for(int i=1;i<p;i++)
	{
		ans+=mi(k[i]);
	}
	cout<<ans;
	return 0;
}
