#include<bits/stdc++.h>
using namespace std;
long c[10000000];
long p[10000000];
long k[10000000];
int cmp(int g,int y)
{
	if(g>y)
	    return g>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long a,b,m,s=0;
    cin>>a>>b;
    for(int i=1;i<=a;i++) 
    {
    	cin>>c[i];
	}
	sort(c+1,c+1+a);
	
	long long r=1;
	while(c[a-b+1]>0)
	{
	    for(int i=1;i<=b;i++)
	    {
		    k[r]+=c[a-i+1]%2;
		    c[a-i+1]/=2;
		    
	    }
		
	    r++;
	}
	for(int i=1;i<=r;i++)
	{
		if(k[i]==b)
		{
			m=1;
			for(int j=1;j<=i-1;j++)
			{
				m*=2;
			}
			
			s+=m;
		}
	}
	cout<<s;
	
		
} 
