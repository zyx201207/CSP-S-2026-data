#include<bits/stdc++.h>
using namespace std;
int n,m,b[200005][40],mt=0,mx=0;
int book[200005];
void ss(int x,int sm,int d)
{
	if(d>=m||book[sm]==1)
		return ;
	book[sm]=1;
	int a=x,t=0,u=1;
	int r[40]={},rs[40]={};
	while(a)
	{
		int c=a/2;
		if(c*2!=a)
		{
			r[t]=1;
			t++;
		}
		else
		{
			r[t]=0;
			t++;
		}
		a=c;
	}
	x=0;
	for(int k=0;k<max(mt,t);k++)
	{
		if(r[k]==1&&b[sm][k]==1)
			rs[k]=1;
		x=x+rs[k]*u;
		u=u*2;
	}
	if(x>mx)
		mx=x;
	ss(x,sm++,d++);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a,t=0;
		cin>>a;
		while(a)
		{
			int c=a/2;
			if(c*2!=a)
			{
				b[i][t]=1;
				t++;
			}
			else
			{
				b[i][t]=0;
				t++;
			}
			a=c;
		}
		mt=t;
	}
	for(int i=1;i<=n;i++)
	{
		memset(book,0,sizeof book);
		int xi=0,ui=1;
		for(int j=0;j<mt;j++)
		{
			xi=xi+b[i][j]*ui;
			ui*=2;
		}
		ss(xi,i,1);
	}
	cout<<mx;
	return 0;
}
