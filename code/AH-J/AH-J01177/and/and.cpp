#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int a[1000001],sum;
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[n];
	for(int i=n-1;i>n-m;i--)
	{
		sum&=a[i];
	}
	cout<<sum;
    return 0;
}

