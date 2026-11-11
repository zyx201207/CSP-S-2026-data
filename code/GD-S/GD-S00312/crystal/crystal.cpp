#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[500005],l=1,r,ans,s;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	r=n;
	for(int i=2;i<=n;i++)
	{
		s=s+(a[i]-a[i-1])*(i-l);
		while(s>m)
		{
			s=s-(a[i]-a[l]);
			l++;
		}	
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
