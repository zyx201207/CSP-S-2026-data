//My sorrow is made of water.
//Who has made my sorrow?
//.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
		{x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=5e3+7;
const int M=2e6+7;
int c,t,n;
int ans,cnt;
ll d,minn[N][N];
ll x[M];
void go(int l,int r,ll y)
{
	if(l==r)
	{
		if(y<minn[l][r])
			{minn[l][r]=y;ans=1;}
		else ans++;
		return;
	}
	if(minn[l][r]<y)
		return;
	minn[l][r]=y;
	for(int i=l+1;i<=r;i++)
	{
		if(d<x[i]-x[l])
			break;
		go(i,r,y+1);
	}
}
int chk(int l,int r)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			minn[i][j]=1e19;
	ans=0;
	go(l,r,0);
	if(ans==2)
		return 1;
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int i,j;
	c=read();t=read();
	while(t--)
	{
		cnt=0;
		n=read();d=read();
		for(i=1;i<=n;i++)
			x[i]=read();
		if(c==11||c==12)
		{
			if(d<=x[2]-x[1])
			{
				printf("0\n");
				continue;
			}
			for(i=3;i<=n;i++)
				if(x[i]-x[1]>d)
					break;
			printf("%d\n",max(0,n-2*i+5));
		}
		for(i=1;i<n-1;i++)
			for(j=i+2;j<=n;j++)
				if(chk(i,j))
					cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
