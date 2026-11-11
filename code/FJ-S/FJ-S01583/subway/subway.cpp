#include<bits/stdc++.h>
#define TNF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define int long long
using namespace std;
using pii=pair<int,int>;
int n,m,dd,q;
int a[500010];
vector<pii>v[500010];
int d[500100];
bool st[500010];
void dj(int x)
{
	memset(st,0,sizeof st);
	memset(d,TNF,sizeof d);
	d[x]=0;
	priority_queue<pii,vector<pii>,greater<>>q;
	q.push({0,x});
	while(q.size())
	{
		auto ff=q.top();
		q.pop();
		if(st[ff.second]==1)continue;
		st[ff.second]=1;
		for(auto i:v[ff.second])
		{
			if(d[ff.second]+i.second<d[i.first])
			{
				d[i.first]=d[ff.second]+i.second;
				q.push({d[i.first],i.first});
			}
		}
		
	} 
}
int l[500010],r[500010];
void ddd()
{
	cin>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>l[j]>>r[j];
			for(int k=1;k<=j-1;k++)
			{
				v[l[k]].push_back({l[j],r[j]+r[k]});
				v[l[j]].push_back({l[k],r[j]+r[k]});
			}
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;	
		dj(l);
		cout<<d[r]+a[l]+a[r]<<endl;
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int qq;
	cin>>qq;
	int t=1;
	//cin>>t;
	while(t--)ddd();
}
/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
 0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
 */

