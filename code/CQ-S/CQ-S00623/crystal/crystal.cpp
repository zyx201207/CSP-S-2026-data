#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define int long long
namespace lzz
{
	int n,m;
	int a[N],ans;
	int main()
	{
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i]; sort(a+1,a+n+1);
		for(int i=1,j=1,sum=0;i<=n;i++)
		{
			if(i>1)sum+=(a[i]-a[i-1])*(i-j);
			while(j<=i&&sum>m)sum-=a[i]-a[j],j++;
			ans=max(ans,i-j+1);
		}cout<<ans<<'\n';

		return 0;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	return lzz::main();
}

