#include<bits/stdc++.h>
#define ll long long
using namespace std;

int w[500005];
int k[505],t[505][500005];
vector<int> sta[500005];

bool check(int x,int y,int tgt)//ÊÇ·ñÇÐ»»Â·Ïß 
{
	bool flag1 = false,flag2 = false;
	for(int i=0;i<sta[x].size();i++)
	{
		for(int j=0;j<sta[y].size();j++)
			if(sta[x][i] != sta[y][j])
				flag1 = true;
		if(flag1) break;
	}
	for(int i=0;i<sta[y].size();i++)
	{
		for(int j=0;j<sta[tgt].size();j++)
			if(sta[y][i] == sta[tgt][j])
				flag2 = true;
		if(flag2) break;
	}
	return flag1&&flag2;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,i,j;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			int aij;
			cin>>aij>>t[i][j];
			sta[aij].push_back(i);
		}
	}
	for(i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ll ans = w[x]+t[x][x]+w[y];
		for(j=min(x,y);j<max(x,y);j++)
		{
			ans += t[j][j+1];
			if(check(j,j+1,y) && j!=max(x,y)-1)
				ans += t[j+1][j+1];
		}
		cout<<ans<<"\n";
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
