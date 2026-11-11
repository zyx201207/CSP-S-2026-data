#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],sum,p;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==m)
	{
		sum=a[0];
		for(int i=1;i<n;i++)sum&=a[i];
		cout<<sum;
		return 0;
	}	
	return 0;
}
