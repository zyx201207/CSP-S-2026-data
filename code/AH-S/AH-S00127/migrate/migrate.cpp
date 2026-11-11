#include<bits/stdc++.h>
using namespace std;
int n,d;
int cnt=0;
int a[15];
int dis[15][15];
int f[15][15];
int dfs(int l,int r)
{
	if(l>r) return 0;
	if(a[r]-a[l] <= d)
	{
		dis[l][r]=1;
		return dis[l][r];
	}
	for(int i = l;i<=r;i++)
	{
		dis[l][r]=min(dis[l][r],dfs(l,i)+dfs(i,r));
	}
	return dis[l][r];
}
int count(int x)
{
	int ans=0;
	while(x)
	{
		x&=(x-1);
		ans++;
	}
}
void g(int l,int r,int id,int la,int zt)
{
	if(count(zt) >  dis[l][r])
	{
		return ;
	}
	if(id==r)
	{
		zt=(zt<<1)|1;
		if(zt^cnt!=0)
		{
			f[l][r]++;
		}
		return ;
	}
	if(a[id+1]-a[la]<=d)
	{
		g(l,r,id+1,la,zt<<1);
	}
	g(l,r,id+1,id,(zt<<1)|1);
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		
		cin >> n >> d;
		if(n>9)
		{
			for(int i = 1;i<=n;i++)
			{
				cin >> d;
			}
			cout << "0\n";
			continue;
		}
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i];
			for(int j = 1;j<=n;j++)
			{
				dis[i][j]=2e9;
				f[i][j]=0;
			}
			dis[i][i]=0;
		}
		for(int i = 1;i<=n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				dfs(i,j);
			}
		}
		int ans=0;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				cnt=0;
				g(i,j,i,i,0);
				if(f[i][j]==2)
				{
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/








/*
**f is good.give me some points!
===================
miao miao miao dxr is lovely duck.
==================
sto sto % ZTM % orz orz
ZTM bao you me get S1=
===================
i'm cat illness.dxr is duck illness.kjr is pig illness.
kjr said if we call yiyuzheng zhuwen,the yiyuzheng people will jianshao 99%
===================
wns && dzh 99
it is difficult to guess that who yi shang ke just ti dao wns~~~.
===================
in my hua xue class
one teacher dazi "dwd"(de wen du) the first is my another hua xue teacher's name.
too yummy
they are ___(tian kong)!
and their name both is hui wen chuang
more yummy
*/
/*
if i cannot get s1=,wns's mother fly in the space 
i need s1= please orz orz orz
make some answers that filled with zero.
*/ 
