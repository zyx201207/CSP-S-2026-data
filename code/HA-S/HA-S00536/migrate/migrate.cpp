#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,d,a[N];
vector<int>g[N];
int find(int l,int r)
{
	int tmp=a[l],k=l,cnt=0;
	while(k<r)
	{
		tmp+=d;
		while(k<=n&&a[k]<=tmp){k++;}
		k--;
		tmp=a[k];
		cnt++;
	}
	return cnt;
}
int dfs(int x,int ed,int cnt,int ned)
{
	if(x>ed){return 0;}
	if(cnt>ned){return 0;}
	if(x==ed){return (cnt==ned);}
	int ans=0;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		ans+=dfs(y,ed,cnt+1,ned);
	}
	return ans;
}
bool check(int l,int r)
{
	int fl=find(l,r);
	return (dfs(l,r,0,fl)==2);
}
void solveA()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1){cout<<0<<"\n";return;}
	int tmp=a[2]-a[1];
	d/=tmp;
	if(d<=1){cout<<0<<"\n";return;}
	int res=d+d;
	int ans=max(0ll,n-res+1);
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	if(c==11||c==12)
	{
		while(T--)
		{
			solveA();
		}
	}
	else
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				g[i].clear();
				cin>>a[i];
				for(int j=1;j<i;j++)
				{
					if(a[i]-a[j]<=d)
					{
						g[j].push_back(i);
					}
				}
			}
			int ans=0;
			for(int l=1;l<n;l++)
			{
				for(int r=l+1;r<=n;r++)
				{
					ans+=check(l,r);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
