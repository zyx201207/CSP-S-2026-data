#include<bits/stdc++.h>
using namespace std;
struct qwetyuiop
{
	int hao;
	int zhan[1005][4];
}xian[505];
int kzht[20005];
int xxx[100005],yyy[100005];
int main()
{
	freopen("r","subway.in",stdin);
	freopen("w","subway.out",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>kzht[i];
	}
	for(int i=1;i<=n;i++)
	{
		int kkkk;
		cin>>kkkk;
		xian[i].hao=kkkk;
		for(int j=1;j<=kkkk;j++)
		{
			cin>>xian[i].zhan[j][1]>>xian[i].zhan[j][2];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int tttt;
		cin>>xxx[i]>>yyy[i];
		tttt+=kzht[xxx[i]]+kzht[yyy[i]];
	}
	return 0;
}
