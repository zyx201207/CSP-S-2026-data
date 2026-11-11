#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=5e5+7;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	ll a[INF];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll maxn=-INF;
	int s=0;
	ll k;
	for(int i=1;i<=n;i++)
	{
		k=max(maxn,a[i]);
		maxn=k;
		if(k==a[i])
		{
			s++;
		}
		if(s==3)
		{
			break;
		}
	}
	cout<<maxn;
	return 0;
}
