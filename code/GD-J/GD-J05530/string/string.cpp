#include<iostream>
using namespace std;
long long n,a[200005],l;
char c[200005];
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout"); 
	
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n/2;i++)
	{
		if(c[i]!=c[n-i])
		{
			l+=min(a[n-i],a[i]);
			if(i!=1&&abs(a[i-1]-a[n-i+1])&&c[i]!=c[n-i+1])
			l+=abs(a[i]-a[n-i+1]);
		}
	}
	cout<<l;
}
