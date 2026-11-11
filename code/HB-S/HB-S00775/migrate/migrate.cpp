#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll x[2000005],ans;
int n,en,cnt,minn=1e9;ll d;
bool gm[2000005],has;
vector<int> gra[2000005];
void dfs(int now,int l)
{
	if(l>minn) return;
	if(now==en)
	{
		if(l<minn) cnt=1,minn=l;
		else if(cnt==0) cnt++,minn=l;
		else if(l==minn) cnt++;
		if(cnt>2){has=0;return;}
	}
	for(int i=0;i<gra[now].size();i++)
	{
		if(gm[gra[now][i]]) continue;
		gm[gra[now][i]]=1;
		dfs(gra[now][i],l+1);
		gm[gra[now][i]]=0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					gra[i].push_back(j);
				}
				else break;
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				en=j,has=1;
				dfs(i,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
