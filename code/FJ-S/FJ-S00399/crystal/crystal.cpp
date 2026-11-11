#include<bits/stdc++.h>
namespace My
{
	using namespace std;
	typedef long long ll;
	const int N=1000005;
	int n;
	ll m,a[N],c;
	ll q[N],h,t,ans;
	int main()
	{
//		system("fc crystal.out crystal5.ans");
//		freopen("crystal5.in","r",stdin);
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			c+=(t-h)*(a[i]-a[i-1]);
			q[++t]=a[i];
			while(c>m)
			{
				c-=a[i]-q[h+1];
				h++;
			}
			ans=max(ans,t-h);
		}
		cout<<ans;
		return 0;
	}
}
int main()
{
	return My::main();
}
