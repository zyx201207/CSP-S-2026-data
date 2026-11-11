#include<bits/stdc++.h>
using namespace std;
const int N=5e5+505;
int C,n,m,d,q;
struct qq
{
	int u;
	long long w;
};
vector<qq>r[N];
long long a[N];
int k[N];
long long s[N];
bool f[N];
map<pair<int,int>,long long>ff;
long long spfa(int be,int en)
{
	priority_queue<pair<long long,int>>x;
	x.push({0,be});
	memset(s,0x3f,sizeof s);
	memset(f,0,sizeof f);
	s[be]=a[be];
	f[be]=1;
	while(!x.empty())
	{
		auto xx=x.top();
		x.pop();
		for(auto i:r[xx.second])
		{
			if(s[xx.second]+i.w<s[i.u]&&f[i.u]==0)
			{
				s[i.u]=s[xx.second]+i.w;
				if(f[i.u]==0)
				{
					x.push({s[i.u]*-1,i.u});
				}
				f[i.u]=1;
			}
		}
	}
	return s[en]+a[en];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x;
			long long y;
			cin>>x>>y;
			r[x].push_back({i+m,y});
			r[i+m].push_back({x,y});
		}
	}
	for(int i=1;i<=q;i++)
	{
		int be,en;
		cin>>be>>en;
		if(ff[{be,en}]==0)
		{
			ff[{be,en}]=ff[{en,be}]=spfa(be,en);
		}
		cout<<ff[{be,en}]<<"\n";
	}
}
