#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int a[50005];
	int b[50005];
	cin>>n>>m;
	int j;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int p;
	int v=0;
	int w;
	for(int i=n;i>=1;i--)
	{
		w=m;
		p=i;
		while(w==0)
		{
			if(p-1>=1)
			{
				j=a[i]-a[p-1];
				if(w>=j)
				{
					w-=j;
					b[i]++;
					p--;
				}
				else
				{
					w=0;
				}
				
			}
			
		}
		if(b[i]>=v)
		{
			v=b[i];
		}
	}
	cout<<v;
	return 0;
}
