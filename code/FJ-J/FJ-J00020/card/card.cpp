#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[5000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i];
	}
	return 0;
}

