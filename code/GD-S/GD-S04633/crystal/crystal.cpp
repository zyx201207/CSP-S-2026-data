#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],s[N];
long long ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
		s[i]+=s[i-1];
	}
	long long l=1;
	long long sum=0;
	for(long long  r=2;r<=n;r++)
	{
		sum+=(s[r-1]-s[r-2])*(r-l);
		while(sum>m and l<r)
		{
			sum-=s[r-1]-s[l-1];
			l++;
		} 
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
