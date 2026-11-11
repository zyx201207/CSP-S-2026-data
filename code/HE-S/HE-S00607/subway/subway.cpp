#include <bits/stdc++.h>
using namespace std;

const int M=5*1e5;
const int N=550;

int c,n,m,d,q;
int dis[M];
int len[M][N];
vector<int> pic[M];

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>dis[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>len[i][j];
		}
	}
	
	while(q--)
	{
		int u=0,v=0;
		cin>>u>>v;
	    cout<<u<<'\n';
	}
	
return 0;}
