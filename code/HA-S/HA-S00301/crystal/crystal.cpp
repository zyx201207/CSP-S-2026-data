#include<bits/stdc++.h>

#define ll long long

using namespace std;

const ll N=5e5+10;

int n;
ll m;
ll a[N];
ll ans[N];
int l,r,mid;
int k,co;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		l=1,r=i-1;
		k=0;
		while(l<=r)
		{
//			cout<<"mid "<<mid<<"\n";
			mid=(l+r)/2;
			if(mid*a[i]-(ans[i-1]-ans[i-1-mid])<=m)
			{
				k=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		ans[i]=ans[i-1]+a[i];
//		cout<<i<<" "<<k<<"\n";
		co=max(co,k+1);
	}
	cout<<co<<"\n";
	return 0;
}
