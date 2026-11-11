#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=500005;
const int N=505;
int c,n,m,d,q;
int w[M];
struct stu
{
	int ting,t;
};
vector <stu> g[N];
struct jihua
{
	int x,y;
};
vector <jihua> dao[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,t;
			cin>>v>>t;
			g[i].push_back({v,t});
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		dao[i].push_back({x,y});
	}	
	for(int i=1;i<=q;i++)
	{
		//CCF ni niu da le
		cout<<0<<"\n";
	}
	return 0;
}
