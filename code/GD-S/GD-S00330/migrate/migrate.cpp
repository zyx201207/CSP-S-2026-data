#include<bits/stdc++.h>
using namespace std;

long long f(long long a,long long n)
{
	if(n<=0)
	{
		return 1;
	}
	long long re;
	for(long long i=1;i<a||i<n;i++)
	{
		re+=f(a,n-i);
	}
	return re;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	if(c==11||c==12)
	{
		while(t--)
		{
			long long n,d;
			vector<long long> x(n);
			for(int i=0;i<n;i++)
			{
				cin>>x[i]; 
			}
			long long a=d/(long long)(x[2]-x[1]);
			cout<<f(a,n);
		    
		}
		return 0;
	}

	while(t--)
	{
		int n,d;
		vector<int> x(n);
		for(int i=0;i<n;i++)
		{
			cin>>x[i]; 
		}
		
	}
    return 0;
}
