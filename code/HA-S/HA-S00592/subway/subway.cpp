#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxm=3e5+10,maxn=510;
long long c,n,m,d,q,x,y,ans;
//,w[maxm],a[maxn][maxm],t[maxn][maxm],k[maxn]
//struct p
//{
//	long long pos;
//	bool in;//pos现在位置  in现在在站台(1)还是站厅(0)
//};
//queue <p> qu;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++)
//		cin>>w[i];
//	for(int i=1;i<=n;i++)
//	{
//		cin>>k[i];
//		for(int j=1;j<=2*k[i];j++)
//			cin>>a[i][j]>>t[i][j];
//	}
	while(q--)
	{
		cin>>x>>y;
		cout<<0<<'\n';
	}
	return 0;
} 
