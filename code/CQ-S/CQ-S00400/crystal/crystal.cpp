#include<bits/stdc++.h>
using namespace std;
#define gm 0
#define int long long
const int N=5e5+5;
int n,m;
int a[N], d[N];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL); 
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+n+1);
	int ans=0;
	map<int, int> mp;
	if(gm)
	{
		gunmu :
			int i=1;
			for(int j=1; j<=n; j++)
			{
				d[j]=abs(a[j]-a[i]);
				cout<<d[j]<<" ";
			}
			int q=i,t=m,k=0;
			while(t>0)
			{
				if(q<=n && t>=d[q]) t-=d[q], q++, k++;
				else break;
			}
			cout<<k<<endl;	
			return 0;
	}
	else if(m==gm)
	{
		for(int i=1; i<=n; i++)
		{
			mp[a[i]]++;
			ans=max(ans, mp[a[i]]);
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(n<=500)
	{
		gun_mu_gun_mu_gun_mu :
			int p,q,t,k;
			for(int i=1; i<=n; i++)
			{
				if(mp[a[i]]) continue;
				mp[a[i]]=1;
				for(int j=1; j<=n; j++)
					d[j]=abs(a[j]-a[i]);
				q=i,t=m,k=0;
				while(t>0)
				{
					if(q<=n && t>=d[q]) t-=d[q], q++, k++;
					else break;
				}
				ans=max(ans, k);
			}
			cout<<ans<<endl;
			return 0;
	}
	else 
	{
		int dr=a[2]-a[1];
		for(int i=2; i<=n; i++)
		{
			if(a[i]-a[i-1] != dr) break;
			else if(i==n) goto gunmu;
		}
	}
	goto gun_mu_gun_mu_gun_mu;
	return 0;
}
