#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],sum,cnt;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		sum=sum+a[i];
	}
	sum=sum/n;
	for(int i=1;i<=n;i++)
	{
	    int t=a[i]-sum;
		if(a[i]<=sum || t==1 || t==2 )cnt++;
	}
	cout<<cnt;
    return 0;
}
