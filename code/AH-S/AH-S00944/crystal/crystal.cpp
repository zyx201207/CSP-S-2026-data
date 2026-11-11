#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,mid,sum,maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1,r=1;
	while(r<=n+1)
	{
		if(r==n+1)
		{
			if(sum<=m)
			{
				maxn=max(maxn,r-l);
				break;
			}
		}
		sum+=(a[r]-a[r-1])*(r-l);
		if(sum>m)
		{
			maxn=max(maxn,r-l);
			sum-=(a[r]-a[r-1])*(r-l);
			sum-=a[r-1]-a[l];
			l++;
			r--;
		}
		r++;
	}
	cout<<maxn;
	return 0;
} 
