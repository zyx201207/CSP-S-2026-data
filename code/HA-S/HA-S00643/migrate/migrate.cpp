#include<bits/stdc++.h>
using namespace std;
long long n,c,t,d,minn=2147483647;
long long a[4000005];
long long jj[4000005];
long long book[4000005];
long long bb[2][4000005];
void f(int x,int step)
{
	if(step>minn)
	{
		return;
	}
	if(x==n)
	{
		minn=step;
		jj[step]++;
		return ;
	}
	for(int i=1;i<=d;i++)
	{
		int tx=x+i;
		if(tx>=0)
		{
			if(tx<=n&&book[tx]==0&&bb[1][tx]==1)
			{
				book[tx]=1;
				f(tx,step+1);
				book[tx]=0;
			}
		}
		else if(tx<0)
		{
			if(tx<=n&&book[tx]==0&&bb[0][tx]==1)
			{
				book[tx]=1;
				f(tx,step+1);
				book[tx]=0;
			}
		}
		
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>t;
	if(c==0)
	{
		
		while(t--)
		{
			memset(jj,0,sizeof jj);
			memset(bb,0,sizeof bb);
			cin>>n>>d;
			int sx;
			for(int i=1;i<=n;i++)
			{
				
				cin>>a[i];
				if(i==1)
				{
					sx=a[i];
				}
				if(a[i]>=0)
				{
					bb[1][i]=1;
				}
				else
				{
					bb[0][i]=1;
				}
			}
			f(sx,1);
			sort(jj+1,jj+1+n);
			if(jj[n]==2)
			{
				cout<<1;
			}
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
