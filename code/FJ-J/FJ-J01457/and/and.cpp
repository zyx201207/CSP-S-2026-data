#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],c[40]={0,0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int n,m;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int d=a[n],sum=a[n],num=1;
	bool p=0;	
	for(int j=n-1;j>=1;j--)
	{
		d=a[n];
		for(int i=1;i<=32;i++)
		{
			d-=c[i];
			if(a[j]==d)
			{
				if(num<m)
				{
					sum&=a[j];
					num++;
				}
				else 
				{
					p=1;
					break;
		    	}
			}
		}
		
	    if(p)
	    {
	    	break;
		}
	}
	if(num<m)
	{
		p=0;
		for(int j=n-1;j>=1;j--)
		{
			d=a[n];
			for(int i=1;i<=32;i++)
			{
				d-=c[i];
				if(a[j]==d)
				{
					if(num<m)
					{
						sum&=a[j];
						num++;
					}
					else 
					{
						p=1;
						break;
		    		}
				}
				d=a[n];
			}
		
	        if(p)
	    	{
	    		break;
			}
		}
	}
	cout<<sum;
	return 0;
}
//mj;
