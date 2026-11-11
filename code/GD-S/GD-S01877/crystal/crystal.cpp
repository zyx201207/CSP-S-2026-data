#include <bits/stdc++.h>
using namespace std;
int n,m,y,z,d;
int ans,f,fx=1e9+5,x,s,j;
int a[500005],sum[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	j=n;
	sort(a+1,a+n+1);
	int i;
	for(i=1;i<=n;i++){
		s=a[j]*(j-i+1)-(sum[j]-sum[i-1]);
		while(m<s&&j>i)
		{	
			s=a[j]*(j-i+1)-(sum[j]-sum[i-1]);	
			j--;
		}
		ans=max((j-i+1),ans);
		while(m>s&&j<=n)
		{
			s=a[j]*(j-i+1)-(sum[j]-sum[i-1]);
			ans=max((j-i+1),ans);
			j++;
		}
	}
	cout << ans;
}

