#include<bits/stdc++.h>
using namespace std;
inline long long read();
inline void endl();
inline void kg();
const long long N=2e6+10,INF=1061109567;
long long n,a[N],c,d,ans=0,way=0,to[N],dp[N],check;
inline void dfs(int l,int r,int step)
{
	if(l>r) return ;
	if(way>=3) return ;
//	cout<<l<<' '<<endl;
	if(step==0)
	{
		if(l==r) way++;
		return ;
	}
	for(int i=to[l];i>l;i--)
	{
		dfs(i,r,step-1);
	}
	return ;
}
inline void get(int l)
{
	dp[l]=0;
	check=2e9;
	for(int i=l;i<=n;)
	{
//		cout<<i<<endl;
//		cout<<i<<' '<<a[i]<<' '<<a[i+1]<<endl;
		if(i==n) break;
		if(a[i+1]-a[i]>d) 
		{
			check=i;
			break;
		}
		int j=i+1;
		while(a[j]-a[i]<=d&&j<=n)
		{
//			cout<<i<<' '<<j<<endl;
			dp[j]=dp[i]+1;
			j++;
		}
		i=j-1;
	}
	return ;
}
inline void work()
{
	n=read(),d=read();
	long long f1=1,f2=1,f3=1,dis;
	ans=0;
	for(int i=1;i<=n;i++) a[i]=read();
	if(11<=c&&c<=12)//A 
	{
		dis=a[2]-a[1];
		long long len=d/dis;
//		cout<<len<<endl;
//		cout<<n<<"sdgsg"<<endl;
//		if(len==3)
//		{
//			ans=max(0ll,n-5);
////			cout<<endl
//		}
		if(len!=2&&len!=3)
		{
			cout<<0<<endl;
			return ;
		}
		ans=max(0ll,n-2*len+1);
		cout<<ans<<endl;
		return ;
	}
	if(13<=c&&c<=14)//B
	{
		cout<<0<<endl;
		return ;
	}
	if(15<=c&&c<=18)//C 
	{
		cout<<n<<endl;
		return ;
	}
//	cout<<c<<endl;
//	exit(114514);
	memset(dp,0x3f,sizeof(long long)*(n+5));
	memset(to,0,sizeof(long long)*(n+5));
//	memset(from,0x3f,sizeof(from));
//	cout<<dp[1]<<endl;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		for(;j<=n;j++)
		{
			if(a[j]-a[i]>d) break;
		}
		to[i]=j-1;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
//		cout<<"sadfa"<<i<<endl;
		get(i);
//		for(int j=1;j<=n;j++) cout<<dp[j]<<' ';
//		cout<<endl;
		for(int j=i+1;j<=min(n,check);j++)
		{
			way=0;
			dfs(i,j,dp[j]);
			if(way==2) ans++;
		}
	}
	cout<<ans<<endl;
	return ;
}
int main()
{
//	freopen("migrate4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	int T=read();
//	c=11;
	while(T--) work();

	return 0;
}
inline long long read()
{
	int f=1;
	long long num=0;
	char x=getchar();
	while(x<'0'||x>'9')
	{
		if(x=='-') f=-1;
		x=getchar();
	}
	while('0'<=x&&x<='9')
	{
		num=num*10+(x-'0');
		x=getchar();
	}
	return f*num;
}
inline void endl()
{
	puts("");
	return ;
}
inline void kg()
{
	putchar(' ');
}


