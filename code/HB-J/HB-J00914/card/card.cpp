#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int m,n;
using ll=long long;
int a[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	cout<<a[n];
	return 0;
}
