# include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
int ans=0;
bool pd4=1,pdk=1;
map<int,int> mpk;
void dfs(int x,int q,int tmp)
{
	if(tmp<ans) return;
	if(q==m)
	{
		ans=max(ans,tmp);
		return;
	}
	if(x>n) return;
	dfs(x+1,q+1,tmp&a[x]);
	dfs(x+1,q,tmp);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=4) pd4=0;
		long long p=1,k=0;
		while(1)
		{
			if(a[i]*1LL==p-1)
			{
				mpk[k]++;
				break;
			}
			p*=2;
			k++;
			if(p>1073741824*1LL)
			{
				pdk=0;
				break;
			}
		}
	}
	sort(a+1,a+n+1);
	if(n==m)
	{
		ans=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(n-1==m)
	{
		ans=INT_MAX;
		for(int i=1;i<=m;i++)
		ans&=a[i];
		cout<<ans<<"\n";
		return 0;
	}
	if(pd4)
	{
		map<int,int> mp;
		for(int i=1;i<=n;i++)
		{
			mp[a[i]]++;
		}
		if(mp[3]>=m) cout<<3<<"\n";
		else if(mp[3]+mp[2]>=m) cout<<2<<"\n";
		else if(mp[3]+mp[1]>=m) cout<<1<<"\n";
		else cout<<0<<"\n";
		return 0;
	}
	if(pdk)
	{
		int cnt=0;
		for(int i=30;i>=0;i--)
		{
			if(mpk.count(i)) cnt+=mpk[i];
			if(cnt>=m)
			{
				int p=1;
				for(int j=1;j<=i;j++)
					p*=2;
				cout<<p-1<<"\n";
				return 0;
			}
		}
		return 0;
	}
	dfs(2,1,a[1]);
	dfs(2,0,INT_MAX);
	cout<<ans<<"\n";
	return 0;
}
