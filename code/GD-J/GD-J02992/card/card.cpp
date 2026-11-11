#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int v[1000005];
int l;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	int n,m,x;
	bool o=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) o=1;
	}
	l=n;
	if(!o)
	{
	 	for(int i=1;i<=n;i++)
		{
			cout<<a[n]<<" ";
		}
	}
	else
	{
		
		for(int w=1;w<=n;w++)
		{
			l=n-w+1;
			for(int i=w+1;i<=n;i++)
			{
				if(l==a[i])
				{
					for(int j=n;j>=1;j--)
					{
						if(a[i]!=a[j]) l=i;
					}
				} 
				v[a[i]]++;
				v[a[i]]--;
			}
			cout<<a[l]<<" ";
		}

		
	}	
	return 0;
}


