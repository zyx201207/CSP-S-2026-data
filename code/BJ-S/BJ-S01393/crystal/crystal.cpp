#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0,s=0,sm=0;
	for(int r=1,l=1;r<=n;r++)
	{
		sm+=a[r],s=(r-l+1)*a[r]-sm;
		while(s>m&&l<r) sm-=a[l],s-=a[r]-a[l],l++;
		//~ cout<<l<<" "<<r<<endl;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
