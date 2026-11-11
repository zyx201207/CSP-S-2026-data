#include<bits/stdc++.h> 
using namespace std;
long long a[500005];
long long o[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long max;
	int l;
	int cnt=0;
	cin>>n>>m;
	long long k=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		while(k!=0||l==0)
		{
			cnt++;
			l=i+1;
			k-=a[l]-a[l-1];
			l--;	
		}
		k=m;
		o[i]=cnt;
		cnt=0;					
	}
	sort(o+1,o+n+1);
	for(int i=1;i<=n;i++)
	{
		cout<<o[i];
	}
	cout<<o[n];
	return 0; 
 } 
