#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500050],k[500050];
//int a[501][500001];
//int t[401][500001];
int x,y,sum=0;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
		sum+=w[i];
	}
	while(q--)
	{
		cout<<sum-1<<endl;
	}
	return 0;
//	for(int i=1;i<=n;i++)
//	{
//		k[i]=read();
//		for(int j=1;j<=2*k[i];j++)
//		{
//			a[i][j]=read();
//			t[i][j]=read();
//		}
//	}
//	for(int i=1;i<=q;i++)
//	{
//		x=read(),y=read();
//		cout<<sum<<endl;
//	}
	return 0;
}
