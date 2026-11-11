#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		sum[i]=(a[i]-a[i-1])*(i-1)+sum[i-1];
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(m<sum[i])
		{
			break;
		}
		else cnt=i;
	}
	cout<<cnt<<endl;
	return 0;
}
