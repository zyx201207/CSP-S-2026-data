#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],ans,qzh[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{cin>>a[i];qzh[i]=a[i]+qzh[i-1];}
	sort(qzh+1,qzh+n+1);
	sort(a+1,a+n+1);
	int l=1,r=n,zj;
	while(l<r)
	{
		zj=(l+r)/2;
		if(qzh[zj]-qzh[l-1]>m){l=zj+1;}
		else {r=zj-1;}
	}
	ans=zj-l+1;
	cout<<ans;
    return 0;
}
