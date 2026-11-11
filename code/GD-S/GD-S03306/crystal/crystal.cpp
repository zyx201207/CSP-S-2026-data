#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;

int n,m,a[N],sum;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	int i=1;
	for(;i<n;++i)
	{
		if(a[i+1]-a[i]>=(m-sum)/i)break;
		sum+=(a[i+1]-a[i])*i;
	}
	cout<<i;
	return 0;
 } 
