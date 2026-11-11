#include<iostream>
#include<queue>
using namespace std;
const int N=5e5+5;
int m,n,z,r,d,c,line[505][1005];
int sta[N];
queue<int>q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>z;
	for(int i=1;i<=m;i++)
	{
		cin>>sta[i];
	}
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>line[i][0];
		for(int j=1;j<=line[i][0];j++)
		{
			cin>>k>>line[i][k];
		}
	}
	int x,y;
	while(z--)
	{
		cin>>x>>y;
		cout<<max(sta[x],sta[y])-min(sta[x],sta[y])<<'\n';
	}
	return 0;
}
