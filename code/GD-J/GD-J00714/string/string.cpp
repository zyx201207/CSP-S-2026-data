#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
struct ss
{
	long long a;
	char s; 
}ans[2000005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	long long k=0;
	long long sum=0;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>ans[i].a>>ans[i].s;
		sum+=ans[i].a;
	}
	
	long long p=0,l=0,r=n-1,q=0;
	for(int i=1;i<=sum/2;i++)
	{
		if(p == ans[l].a) 
		{
			l++;
			p=0;
		}
		
		if(q == ans[r].a)
		{
			r--;
			q=0;
		}
		
		if(ans[l].s != ans[r].s) k++;
		
		
		p++;
		q++;
		
	}
	
	cout<<k;
	
	

	
	
	

	
	
	return 0;
}
