#include<bits/stdc++.h>

using namespace std;

const int N = 1005;
int c,n,m,d,q,mm[N],k,x,q1,start,end,a[N][N],qq[N],aa[N][N];
int answer;

int findif(int xl,int zd)
{
	if( a[xl][zd] != 0 ) return xl;
	else return 0;
}

int findout(int xl,int zd)
{
	if( aa[xl][1] == zd ) return 1;
	if( aa[xl][2] == zd ) return 2;

	return 0;
}

void ans(int s,int e)
{
	if(s == e)
	{
		answer += mm[e];
		return;
	}
	for(int i = 1;i <= n;i++ )
	{
		if(!findif(i,s)) continue;
		if(findout(i,s) == 1)
		{
			answer += ( a[i][aa[i][2]] + a[i][aa[i][1]] );
			ans(aa[i][2],e);
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	q1 = q;
	for(int i = 1;i <= m;i++)
	{
		cin>>mm[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin>>k;
		k = 2;
		for(int j = 1;j <= 2;j++ )
		{
			cin>>x;
			cin>>a[i][x];//a[i][j] -> 第i条线路的j号地铁站的换乘时间 
			aa[i][j] = x;//aa[i][j] -> 第i条线路的第j个站点是x 
		}
	}
	while(q1--)
	{
		cin>>start>>end;
		answer = mm[start];
		ans(start,end);
		qq[q - q1] = answer;
	}
	for( int i = 1;i <= q;i++ )
	{
		if(i == q)
		{
			cout<<qq[i];
			return 0;
		}
		else
		{
			cout<<qq[i]<<"\n";
		}
	}
	return 0;
}
