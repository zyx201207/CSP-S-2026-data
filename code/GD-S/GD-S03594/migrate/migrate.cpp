#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+100;
int C,T;
int n,d,xy[MAXN];
bool check(int st,int ed)
{
	int ss=0;
	if (xy[st]+2*d<xy[ed]) return false;
	for (int i=st;i<=ed;i++)
	{
		if (xy[i]+d>=xy[ed]&&xy[st]+d>=xy[i]) ss++;
	}
	if (ss>2) return false;
	else if (ss==2) return true;
	else return false;
}
signed main()
{
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		bool c=true;
		int c2=0;
		int ans=0;
		for (int i=1,x1=0,y1=0;i<=n;i++)
		{
			
			cin>>xy[i];
			if (i!=1)
			{
				x1=xy[i-1];
				y1=xy[i];
				if (c2==0) c2=y1-x1;
				else if (c2!=y1-x1)
				{
					c=false;
				}
			}
		}
		if (c)
		{
			if (d/c2<=1) cout<<0<<endl;
			else if (n-((d/c2)*2-1)<=0) cout<<0<<endl;
			else cout<<n-((d/c2)*2-1)<<endl;
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=i+3;j<=n;j++)
				{
					if (check(i,j))
					{
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
10 22
0 7 14 21 28 35 42 49 56 63
0 35
x 2x 3x 4x 5x 6x 7x 8x 9x
(22/7)x
first >
after 4x
5x
0->
end <2*(22/7)x
len:2
0->14->35
0->21->35

*/
