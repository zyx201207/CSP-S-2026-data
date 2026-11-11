#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,nx,o,o1;
const int MAXM = 1e6,MAXQ = 1e5,MAXN = 505;
int a_m[MAXM],dp[MAXQ];
struct subway_road
{
	int sn;
	int sub_NO[MAXN];
	int t[MAXN];
}a[MAXN];
struct q_data
{
	int x,y;
	bool on_similar_subway;
}b[MAXQ];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a_m[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].sn;
		for(int j=1;j<=a[i].sn;j++)
		{
			cin>>a[i].sub_NO[j];
			cin>>a[i].t[j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i].x>>b[i].y;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].sn;j++)
			{
				if(a[i].sub_NO[j] == b[i].x)
				{
					for(int q=1;q<=a[i].sn;q++)
					{
						if(a[i].sub_NO[q] == b[i].y)
						{
							b[i].on_similar_subway = true;
							nx = i;
							o = b[i].x;
							o1` = b[i].y;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		//???????? 
		if(b[i].on_similar_subway)
		{
			dp[i] = a_m[o]+a[nx].t[b[i].x]+a[nx].t[b[i].y]+a_m[o1];
		}
		//??????
		else
		{
			dp[i] = a_m[b[i].x]+a[nx].t[b[i].x]+a[nx].t[b[i].y]+a_m[b[i].y];
		} 
	}
	for(int i=1;i<=q;i++)
	{
		cout<<dp[i]<<"\n";
	}
}

