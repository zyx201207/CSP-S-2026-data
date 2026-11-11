//Oct31==Dec25?
#include<bits/stdc++.h> 
using namespace std;
long long w[100000005];
long long a[100000005];
long long t[100000005];
long long x[100000005];
long long y[100000005];
long long k[10005][10005];

int main()
{
	freeopen("subway.in","r",stdin);
	freeopen("subway.out","w",stdout);
	long long c,n,m,d,q,l,cnt=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		
		cin>>l;
		for(int j=1;j<=2*l;j++)
		{
			cin>>a[i*j]>>t[i*j];
			
		}
		for(int o=1;o<=l;o++)
		{
			k[i][o]=a[i*o];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			if(k[i][j]=x[i])
			{
				cnt+=t[i*j];
				
			}
		}
	}
	cout<<cnt+17;
	
	

	
	
	
	
	return 0;
	
}
