#include<bits/stdc++.h>
using namespace std;
long long summ;
int c,n,m,qq,d,w[100000],k[505],a[505][50005],t[505][505],f[505];
vector<pair<int,int> >q[114514];

void dfs(int l,int r,int e,int ww)
{
//	cout<<l<<" "<<r<<" "<<e<<" "<<ww<<endl;
	if (l==r)
	{
		summ=min(summ,(long long)e+t[ww][l]+w[l]);
		return ;
	}
//	cout<<q[l].size()<<endl; 
	for (int i=0;i<q[l].size();i++)
	{
		if (ww==0)
		{
			f[l]=1;
//			cout<<l<<" "<<q[l][i].second<<"!!@!#"<<endl;
//			cout<< t[q[l][i].second][l]<<endl;
			dfs(l,r,e+t[q[l][i].second][l],q[l][i].second);
//			f[l]=0;
		}
		else if (f[q[l][i].first]==0)
		{
			
//			cout<<q[l][i].first<<" "<<q[l][i].second<<endl;
			if (ww!=q[l][i].second)
			{
//				cout<<ww<<" "<<q[l][i].first
//				cout<<t[ww][l]<<"  "<<t[q[l][i].second][l]<<"@!#!@#"<<endl;
				dfs(l,r,e+t[ww][l]+t[q[l][i].second][l],q[l][i].second);
//				f[l]=0;
			}
			else
			{
				f[q[l][i].first]=1;
//				cout<<e<<endl;
				dfs(q[l][i].first,r,e,ww);
//				f[q[l][i].first]=0;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			int qqq;
			cin>>a[i][j]>>qqq;
			t[i][a[i][j]]=qqq;
//			cout<<i<<" "<<a[i][j]<<" "<<t[i][a[i][j]]<<endl;
			if (j!=1)
			{
				q[a[i][j]].push_back({a[i][j-1],i});
				q[a[i][j-1]].push_back({a[i][j],i});
			}
		}
	}
	for (int i=1;i<=qq;i++)
	{
		int l,r;
		cin>>l>>r;
		summ=(long long)1e18;
		memset(f,0,sizeof(f));
		dfs(l,r,w[l],0);
		cout<<summ<<endl;
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
*/
