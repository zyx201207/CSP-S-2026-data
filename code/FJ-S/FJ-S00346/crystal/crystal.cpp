#include<bits/stdc++.h>
using namespace std;//lguid 1411360
#define int long long
const int MAXN=5e5+10;
int n,a[MAXN],c[MAXN],m,ans=1;//lguid 1411360
int read()//lguid 1411360
{
	int x=0,f=1;//lguid 1411360
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;//lguid 1411360
		c=getchar();
	}//lguid 1411360
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;//lguid 1411360 //lguid 1411360
}
/*
能s1=我吃
18点17分 //lguid 1411360
*/ 
signed main()
{//lguid 1411360//lguid 1411360
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();//lguid 1411360
	for(int i=1;i<=n;i++)//lguid 1411360
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(a[i]>=a[j]&&a[i]-a[j]<=m)///lguid 1411360/lguid 1411360
				c[++cnt]=a[i]-a[j];
		for(int j=1;j<=cnt;j++)c[j]+=c[j-1];//lguid 1411360
		for(int l=1;l<=cnt;l++)
			for(int r=l+1;r<=cnt;r++)
				if(c[r]-c[l-1]<=m)//lguid 1411360
					ans=max(ans,r-l+1);
	}
	cout<<ans;//lguid 1411360
	return 0; 
}
/*
世界上本没有路，走的人多了，便成了路......
OI这条路真的适合你我吗 
*/
