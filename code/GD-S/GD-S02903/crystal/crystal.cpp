#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
long long n,m,s=0,flag=0,sum=0;
int main()
{
	//freopen("crystl.in","r",stdin);
	//freopen("crystl.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[n]*n-sum<m)
		{
			cout<<n;
			break; 
		}
		else n--;
	}
} 
