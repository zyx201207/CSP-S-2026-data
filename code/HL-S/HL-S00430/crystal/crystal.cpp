#include<bits/stdc++.h>
using namespace std;
long long  a[500005];
bool cmp(long long c,long long d)
{
	return c<d;
}
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=-1;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-1;i++)
	{
	    long long tmp=0,sum=0;
    	for(int j=i+1;j<=n;j++)
    	{
    		sum=(a[j]-a[j-1])*(j-i)+tmp;
    		if(sum<=m)
    		{
    			ans=max(j-i+1,ans);
			}
			else
			{
				break;
			}
			tmp=sum;
		}
	}
	cout<<ans;
	return 0;
}