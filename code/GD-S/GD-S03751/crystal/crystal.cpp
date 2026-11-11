#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	long long sum=0;
	int maxn=-1;
	for(int r=2;r<=n;r++)
	{
		sum+=(r-l)*(a[r]-a[r-1]); 
		while(l<r && sum>m)
		{
			sum-=(a[r]-a[l]);
			l++;
		}
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn<<endl;
	return 0;
}
