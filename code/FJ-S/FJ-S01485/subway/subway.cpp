#include<bits/stdc++.h>
using namespace std;
long long timeb[50000];int c,n,m,d,q;
long long a[500][50000];int fen[10000];
long long b[500][50000];int posfin,starfin;int p1,p2;
int serchf(int s,int fi)
{
	long long cnt=0;
	cnt+=timeb[s];
	cnt+=b[starfin][p1];long long maxx=1e9;
	for(int i=1;i<=fen[1];i++)
	{
		for(int j=1;j<=fen[2];j++)
		{
			if(a[1][i]==a[2][i])
			{
				maxx=min(b[1][i]+b[2][i],maxx);
			}
		}
	}
	cnt+=maxx;long long minn=1e9;
	if(n==3)
	{
		for(int i=1;i<=fen[2];i++)
		{
		for(int j=1;j<=fen[3];j++)
		{
			if(a[2][i]==a[3][i])
			{
				minn=min(b[2][i]+b[3][i],minn);
			}
		}
		}
		
	}
	cnt+=timeb[fi];
	cnt+=b[posfin][p2];
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("subway.in","r",stdin);
	//freopen("subway.in","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>timeb[i];
	}
	long long ttt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>fen[i];
		for(int j=1;j<=fen[i];j++)
		{
			
			cin>>a[i][j]>>b[i][j];
			
		}
		
		
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
		
		for(int j=1;j<=fen[i];j++)
		{
			if(a[i][j]==x)
			{
				starfin=i;
				p1=j;
			}
			if(a[i][j]==y)
			{
				posfin=i;
				p2=j;
			}
			
			
		}
		
		cout<<serchf(x,y)<<endl;
	}
}
	return 0;
} 
