#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+5;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	int ans=1;
	int l=1,r=2;
	a[0]=a[1];
	while(r<=n)
	{
		while(m<(r-l)*(a[r]-a[r-1]))
		{
			m+=(a[r-1]-a[l]);
			l++;
		}
        if(m>=(r-l)*(a[r]-a[r-1]))
        {
        	m-=(r-l)*(a[r]-a[r-1]);
			r++;
			ans=fmaxl(ans,r-l);
		}
	}
	cout<<ans;
	return 0;
}
