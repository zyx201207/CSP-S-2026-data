#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m;
ll a[N];
int ans=0;
bool check(int x)
{
//	cout<<"###"<<x<<" : \n";
	ll sum=0;
	ll minn=0;
	for(int i=1;i<=x;i++)
		sum+=a[x]-a[i];
	minn=sum;
//	cout<<sum<<" ";
	for(int i=x+1;i<=n;i++)
	{
		sum-=a[i-1]-a[i-x];
		ll diff=a[i]-a[i-1];
		sum+=diff*x;
		sum-=diff;
		minn=min(minn,sum);
//		cout<<sum<<" ";
	} 
//	cout<<"\n";
	return (minn<=m);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}

