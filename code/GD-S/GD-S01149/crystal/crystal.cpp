#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],k,l=1,zd;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		k+=(i-l)*(a[i]-a[i-1]);
		while(k>m) k-=a[i]-a[l],l++;
		zd=max(zd,i-l+1);
	}
	cout<<zd;
	return 0;
}
