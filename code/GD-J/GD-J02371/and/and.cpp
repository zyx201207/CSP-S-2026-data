#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll n,m,a[maxn],mx;
bool cmp(ll x,ll y)
{
	return x>y;
}
ll mul(int x)
{
	ll sum=0;
	while(x>0) x/=2,sum++;
	return sum-1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll ans=0,cnt=1,sum=mul(a[1]);
	for(int i=1;i<=sum;i++) cnt*=2;
	for(int i=1;i<=sum+1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]>0&&a[j]>=cnt) ans++;
		}
		if(ans>=m)
		{
			mx+=cnt;
			for(int j=1;j<=n;j++)
			{
				a[j]-=cnt;
			}
		}
		ans=0;
		cnt/=2;
	}
	cout<<mx;
	return 0;
}
