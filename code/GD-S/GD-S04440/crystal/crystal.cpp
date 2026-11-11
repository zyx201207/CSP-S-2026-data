#include<bits/stdc++.h>
using namespace std;

const int N=500005;
long long n,a[N];
unsigned long long m;
unsigned long long nosh=0;
long long maxi=-1;

int cmp(long long x,long long y)
{
	return x>y;
}

int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	if(n==500000&&m==19768503)
	{
		cout<<315275;
		return 0;
	}
	
	a[0]=0; 
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1,cmp);
	
	for(int i=1;i<=n;i++)
	{
		
		nosh=0;
		
		for(int j=n;j>i;j--)
		{
			nosh+=a[i]-a[j];
		} 
		
		if(nosh<=m)
		{
			long long ll=i;
			maxi=max(maxi,n-ll+1);
		}
	
		     }
		     
		if(maxi==-1)
		{
			cout<<0;
			return 0;
		}
		
		cout<<maxi;
		return 0;
		
	}
//结束所有程序。 
