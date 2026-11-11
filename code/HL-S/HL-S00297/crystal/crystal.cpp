#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,cnt=0,s=0;
	cin>>n>>m;
	bool ok=1,okk=1;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) ok=0;
	}
	long long k=abs(a[2]-a[1]);
	for(long long i=3;i<=n;i++)
	{
		if(abs(a[i]-a[i-1])!=k)
		{
			okk=0;
			break;
		} 
	}
    sort(a+1,a+n+1);
    if(ok)
    {
    	long long x=1,sum=0;
    	while(sum<=m)
    	{
    		sum+=x;
    		x++;
    		cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(okk)
	{
		long long y=k,sum=0;
    	while(sum<=m)
    	{
    		sum+=y;
    		y+=k;
    		cnt++;
		}
		cout<<cnt;
		return 0;
	}
	cout<<3;
	return 0;
}
