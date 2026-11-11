#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int b[505][505];
int c2[30];
int c,n,m,d,q;
long long op=0;
long long op2=0;
struct stu
{
	int xl,l,munl;
}zl[250005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>c2[i];
	for(int i=1;i<=n;i++)
	{
		int dl;
		cin>>dl;
		a[i][1]=dl;
		for(int j=2;j<=dl+1;j++)
		cin>>a[i][j]>>b[i][j];
		cout<<endl<<i<<endl;
	}
	for(int i=1;i<=q;i++)
	{
		int minmun=2147483646;
		int x,y;
		int ll=0,cl=0;
		cin>>x>>y;
		int yl=0,xl=0;
		for(int i2=1;i2<=n;i2++)
	{
		int dl;
		dl=a[i2][1];
		for(int j=2;j<=dl;j++)
		if(a[i2][j]==x)
		{
			ll=i2;
			cl=b[i2][j];
			break;
		}
	}
		zl[xl++]={x,ll,c2[x]+cl};
		while(xl>=yl)
		{
			op++;
			if(op==166713) break;
			int now=yl++;
			int nowx=zl[now].xl;
			int nowl=zl[now].l;
			int nowmun=zl[now].munl;
			int newl;
			int newx;
			int add;
			if(a[nowl][nowx]==y)
			{
				minmun=min(nowmun,minmun);
				yl++;
			}
			for(int i2=1;i2<=n;i2++)
			{
				int dl;
				dl=a[i2][1];
			for(int j=2;j<=dl;j++)
				if(a[i2][j]==a[nowl][nowx]&&i2!=nowl&&j!=nowx)
				{
					newl=i2;
					newx=j;
					add=b[nowl][nowx]+b[i2][j];
					zl[xl++]={newx,newl,nowmun+add};
				}
			}
			if(nowx+1>a[nowl][1])
			yl++;
			else	
			zl[xl++]={nowx+1,newl,nowmun};
		}
		
		cout<<minmun<<endl;
	}
	return 0;
}
