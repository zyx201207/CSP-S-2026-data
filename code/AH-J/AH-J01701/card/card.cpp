#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N],c[N];
stack<int> s;
int n,m;
int read()
{
	int p=0,q=1,x;
	char ch=getchar();
	while(ch=='-')
	{
		q=-1;
		ch=getchar();
	}
	x=ch-'0';
	while(x>=0&&x<=9)
	{
		p=p*10+x;
		ch=getchar();
		x=ch-'0';
	}
	return p*q;
}
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==1)
			{
				while(s.top()!=a[j])
				{
					b[s.top()]=0;
					s.pop();
				}
				continue;
			}
			s.push(a[j]);
			b[a[j]]=1;
		}
		for(int j=1;j<=n;j++)
		{
			if(b[j]==1) c[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	return 0;
}
