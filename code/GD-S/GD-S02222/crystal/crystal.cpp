#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long a[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++ )
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int head = 1;
	long long sum = 0;
	int ans = 1;
	for(int i = 2; i <= n; i++ )
	{
		sum+=1ll*(i-head)*(a[i]-a[i-1]);
//		cout<<i<<" "<<sum<<" "<<head<<endl;
		while(sum>m)
		{
			sum-=(a[i]-a[head]);
			head++;			
		}
//		cout<<i<<" "<<sum<<" "<<head<<endl;
		ans=max(ans,(i-head+1));
	}
	cout<<ans<<endl;
}
