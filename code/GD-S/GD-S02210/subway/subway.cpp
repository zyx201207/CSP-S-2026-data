#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e4+5;

int c,n,m,d,q;
int w[MAXN];
vector<pair<int,int> > a[505];
vector<int> fr[MAXN],e[MAXN];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int y,z;
			cin>>y>>z;
			a[i].push_back({y,z});
			fr[y].push_back(i);
		}
	}
	int ans=0;
	
	return 0;
}
