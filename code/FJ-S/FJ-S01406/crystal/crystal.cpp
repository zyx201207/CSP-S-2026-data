#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=0,gs=0;
	for(long long r=1,l=1;r<=n;r++)
	{
		ans+=(a[r]-a[r-1])*(r-l);
		while(ans>m)
		{
			ans-=a[r]-a[l];
			l++;
		}
		gs=max(gs,r-l+1);
	}
	cout<<gs;
	return 0;
} 
