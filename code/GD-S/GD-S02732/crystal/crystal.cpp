#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[50005],ans=1,d[50005],sum,l,r,x;
double ava;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	r=1;
	sum=0;
	while(r<=n&&l<=r)
	{
		while(sum<=m&&r<=n)
		{
			ans=max(ans,r-l+1);
			r++;
	//		cout<<r<<' '<<sum<<endl;
			sum+=((r-l)*(a[r]-a[r-1]));
		}
		
		while(sum>m&&l<=r)
		{
			l++;
	//		cout<<l<<endl;
			sum-=(a[r]-a[l-1]);
		}
	//	cout<<l<<' '<<r<<endl;
	//	cin>>x;
	}
	cout<<ans;
	return 0;
 } 
