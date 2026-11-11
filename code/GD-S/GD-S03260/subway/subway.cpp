#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,n,m,d,q,w[9010],f[9010][9010],a[9010],t[9010];
inline LL read()
{
	register LL x=0;
	register char ch=getchar();
	while(ch<'0'||'9'<ch)
		ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		x=(x<<3ll)+(x<<1ll)+(ch^48);
		ch=getchar();
	}
	return x;
}
int main()
{
//	cout<<f[0][0]<<" "<<LLONG_MAX;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,60,sizeof f);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(LL i=1;i<=m;i++)
		w[i]=read(),f[i][i]=0;
	for(LL i=1;i<=n;i++)
	{
		LL k=read();
		for(LL j=1;j<=k;j++)
			a[j]=read(),t[j]=read();
		for(LL j=1;j<=k;j++)
		{
			for(LL q=1;q<=k;q++)
			{
				f[a[j]][a[q]]=min(f[a[j]][a[q]],t[j]+t[q]);
				f[a[q]][a[j]]=min(f[a[q]][a[j]],t[j]+t[q]);
//				cout<<a[j]<<" "<<a[q]<<"=>"<<t[j]<<"+"<<t[q]<<"="<<t[j]+t[q]<<"\n";
			}
		}
	}
	for(LL k=1;k<=m;k++)
	{
		for(LL i=1;i<=m;i++)
		{
			if(i==k)
				continue;
			for(int j=1;j<=m;j++)
			{
				if(i==j||j==k)
					continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<setw(20)<<f[i][j];
//		cout<<"\n";
//	}
	for(LL i=1;i<=q;i++)
	{
		LL x=read(),y=read();
		printf("%lld\n",w[x]+f[x][y]+w[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

