#include <bits/stdc++.h>
using namespace std;
#define ld long long
ld ti[10005][1000],arr[10005][1000],zhan[10005],fa[100005][2];
int main(int argc, char** argv)
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<n;i++)
	{
		cin>>zhan[i];
		for(int j=0;j<zhan[i]-1;j++)
		{
			cin>>arr[i][j]>>ti[i][j];
		}
	}
	for(int i=0;i<p;i++)
	{
		srand (time(0));
		int v=rand()%n;
		ld z=0;
		for(int i=0;i<v;i++)
		{
			int x=rand()%n,y=rand()%zhan[v];
			z+=ti[x][y];
		}
		cout<<z<<' ';
	}
	return 0;
}
