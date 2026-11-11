//Oct31==Dec25?
#include<bits/stdc++.h> 
using namespace std;
long long a[100000005];
long long b[100000005];
int main()
{
	freeopen("crystal.in","r",stdin);
	freeopen("crystal.out","w",stdout);
	long long n,m,k,c=0,cnt=1,p=1;
	int l=m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		a[i]=k;
		
		
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>0;j--)
		{
			if(a[i]-a[j]<=l)
			{
				p+=1;
				l-=a[i]-a[j] ;
				
			}
		}
		if(cnt<=p)
		{
			cnt=p;
		} 
		p=1;
		l=m;
	}
	
    cout<<cnt;
	
	
	return 0;
	
}
