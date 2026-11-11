#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int n;
long long m;
bool check(int x,int t)
{
	long long sum=0;
	for(int i=1;i<=x;i++)
	{
		sum+=a[t]-a[t-i]; 
	}
	if(sum<=m)return true;
	else return false;
}
int main()
{
	freopen("crystal2.in","r",stdin);
	//freopen("crystal2.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=1;
	for(int i=2;i<=n;i++)
	{
		long long l=1,r=i,mid;
		while(l<r-1)
		{
			mid=(l+r)/2;
			if(check(mid,i))
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		ans=max(ans,r);
	}
	cout<<ans;
	return 0;
}
