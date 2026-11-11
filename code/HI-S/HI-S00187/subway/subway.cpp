#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<long long,long long>>> v(500010);
vector<vector<long long>> ans;
long long n,m,c,d,q;
bool is[500010];
long long w[500010];
void F(int x,int y)
{
	if(is[x])
	{
		cout<<ans[x][y]+w[y]+w[x]<<endl;
		return;
	}
	is[x]=true;
	vector<bool> _is(m+1,false);
	ans[x][x]=0;
	for(int iu=1;iu<=m;iu++)
	{
		int min_val=INT_MAX,min_xia;
		for(int i=1;i<=m;i++)
		{
			if(min_val>ans[x][i]&&!_is[i])
				min_val=ans[x][i],min_xia=i;
		}
		_is[min_xia]=true;
		for(auto t:v[min_xia])
		{
			long long now=ans[x][min_xia]+t.second-w[min_xia];
			ans[x][t.first]=min(ans[x][t.first],now);
		}
	}
	//for(int i=1;i<=m;i++)
	//	cout<<ans[x][i]<<" ";
	//cout<<endl;
	cout<<ans[x][y]+w[y]+w[x]<<endl;
	return;
}
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	ans=vector<vector<long long>>(m+10,vector<long long>(m+10,INT_MAX));
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		vector<pair<long long,long long> >a;
		while(k--)
		{
			long long g,t;
			cin>>g>>t;
			a.push_back(make_pair(g,t));
			for(int k=0;k<a.size()-1;k++)
			{
				v[a[k].first].push_back(make_pair(g,w[a[k].first]+a[k].second+t));
				v[g].push_back(make_pair(a[k].first,w[g]+a[k].second+t));
			}
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		cout<<i<<endl;
//		for(auto p:v[i])
//		{
//			cout<<p.first<<" "<<p.second<<endl;
//		}
//		cout<<endl;
//	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		F(x,y);
	}
	return 0;
}
/*
0 2 5 20 2
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
