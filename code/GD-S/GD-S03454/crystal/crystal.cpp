#include<bits/stdc++.h>
using namespace std;
long long a[511151];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int maxx=-1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=a[1],r=a[n];
	for(int i=l;i<=r;i++)
	{
		int k=0,t;
		long long s=m;
		for(int j=1;j<=n;j++)
			if(a[j]<=i)
				t=j;
		
		for(int j=1;j<=t;j++)
			if(i-a[j]<=s)
			{
				s=s-i+a[j];
				k++;
			}
		maxx=max(maxx,k);
	}
	cout<<maxx;
	return 0;
}
