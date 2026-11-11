#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int a[500010],d[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int p=a[2]-a[1];
	if(m<p)
	{
		cout<<1;
		return 0;
	}
	if(n<=5000)
	{
		int ans=-INF;
		for(int i=1;i<=n;i++)
		{
			int cnt=0,k=m;
			vector<int> v;
			for(int j=1;j<=i;j++) v.push_back(abs(a[i]-a[j]));
			sort(v.begin(),v.end());
			for(auto i:v)
			{
				if(k<i) break;
				k-=i;
				cnt++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	bool ok=true;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=p) ok=false;
	}
	if(ok==false)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		int k=p*(i*(i+1)/2);
		if(k>m)
		{
			cout<<i+1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
