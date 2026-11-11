#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll n, m;
ll a[10005];
int main()
{
	freopen("crystal.out", "r", stdin);
 	freopen("crystal.in", "w",stdout); 
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int r;
	for (int i=n;i>=2;i--)
	{
		int p=i-1;
		ll sum=0;
		while(sum<=m&&p>=1)
		{
			sum+=a[i]-a[p--];
		}
		r=max(r, i-p);
	}cout<<r;
	
	
	return 0;
}

