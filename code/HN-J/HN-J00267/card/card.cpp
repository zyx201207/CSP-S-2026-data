#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],aa=0,bb=0;
stack<int> v;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;i<=n;i++)
		{
			for(int z = 0;z<v.size();z++)
			{
				if(v[z]==a[j])
				{
					for(int zz= 1;zz<=z;zz++)
					{
						v.pop();
					}
				}
			}
			v.push_front(a[j]);
		}
		int f1=0,f2=0;
		for(int z = 0;z<v.size();z++)
		{
			if(v[z]==1)
			{
				f1=1;
			}
			else
			{
				f2=1;
			}
		}
		if(f1)
		{
			bb++;
		}
		else
		{
			aa++;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		cout<<aa<<" "<<bb<<'\n';
	}
	return 0; 
} 
