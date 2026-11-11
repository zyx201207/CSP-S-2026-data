#include <bits/stdc++.h>
using namespace std; 
const int N=1e5*5+5;
long long a[N];
long long ans[N];
int n;
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	    cin>>a[i]; 
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++)
	{
		long long cnt=0;
		for(long long j=i;j>=1;j--)
		{
			cnt+=abs(a[i]-a[j]);
			if(cnt<=m) ans[i]++;
			else break;
		}
	}
	sort(ans+1,ans+1+n);
	cout<<ans[n];
	
	return 0;
} 
