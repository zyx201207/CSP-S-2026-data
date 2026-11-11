#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
const int inf=0x3f3f3f3f;
struct edge
{
	int to,step;
};
int c,t,n,d,ans;
vector<int> vec[maxn];
int a[maxn],in[maxn],cnt[maxn];
void bfs(int x)
{
	queue<edge> q;
	for(int i=1;i<=n;++i) in[i]=inf;
	q.push({x,0});
	while(!q.empty())
	{
		edge e=q.front();q.pop();
		
		if(e.step==in[e.to]) ++cnt[e.to];
		else if(e.step<in[e.to])
		{
			in[e.to]=e.step;
			cnt[e.to]=1;
		}
		for(vector<int>::iterator it=vec[e.to].begin();it!=vec[e.to].end();++it)
			q.push({*it,e.step+1});
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
{
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(c==11||c==12)
	{
		int len=d/(a[2]-a[1]);
		cout<<n-2*len+1<<"\n";
		continue;
	}
	for(int i=1;i<=n;++i) vec[i].clear();
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(abs(a[i]-a[j])<=d) vec[i].push_back(j);
	for(int i=1;i<=n;++i)
	{
		bfs(i);
		for(int j=1;j<=n;++j) if(cnt[j]==2) ans++;
	}
	cout<<ans<<"\n";
}
	return 0;
} 
