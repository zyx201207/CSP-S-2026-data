#include<bits/stdc++.h>
using namespace std;

long long a[500010];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	long long i=0,j=0,maxn=-1,flag=1,sum=0;
	while(j<n)
	{
		if(flag)
		{
			long long mi=(j-i)*(a[j]-a[j-1]);
			sum+=mi;
		}
		if(sum>m)
		{
			sum-=a[j]-a[i];
			i++;
			flag=0;
		}
		else
		{
			maxn=max(maxn,j-i);
			j++;
			flag=1;
		}
	}
	cout<<maxn+1;
}
