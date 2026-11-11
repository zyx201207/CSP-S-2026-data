#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
int n,m;
int a[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	
	int ans=0,j=1;
	for(int i=2;i<=n;i++)
	{
		int t=(a[i]-a[i-1])*(i-j);
		if(m>=t) m-=t,ans=max(ans,i-j+1);
		else
		{
			while(m<t&&j<i) m+=a[i-1]-a[j++],t-=a[i]-a[i-1];
			m-=t;
			ans=max(ans,i-j+1);
		}
	}
	
	cout<<ans;
	
	return 0;
}
/*
Oct31==Dec25?

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
