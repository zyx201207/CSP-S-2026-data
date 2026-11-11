#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,mj,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		mj=m;
	    sum=1;
		for(int j=i-1;j>=1;j--)
		{
			long long edg=a[i]-a[j];
			if(edg<=mj)
			{
				mj-=edg;
				sum++;
			}
			else
			{
				continue;
			} 
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
