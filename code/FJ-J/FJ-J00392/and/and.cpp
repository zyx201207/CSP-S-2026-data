#include<iostream>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int sy[N],tot;
int ns[N],cnt;
int ans;
inline int check(int x,int w)
{
	return (x&(1LL<<w))==(1LL<<w);
}
inline int read(){char cc=getchar();int z=0,fh=1;while((cc<'0' || cc>'9') && cc!='-'){cc=getchar();}if(cc=='-'){fh=-1;cc=getchar();}while(cc>='0' && cc<='9'){z=z*10+cc-'0';cc=getchar();}return z*fh;}
inline void write(int x){if(x==0){putchar('0');return ;}if(x<0){putchar('-');x=-x;}int z[20],tt=0;while(x){z[++tt]=x%10;x/=10;}for(int i=tt;i;i--){putchar(z[i]+'0');}}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sy[++tot]=a[i];
	}
	for(int i=29;i>=0;i--)
	{
		int cnt1=0,cnt0=0;
		for(int j=1;j<=tot;j++)
		{
			if(check(sy[j],i)==1) ++cnt1;
			else ++cnt0;
		}
		if(cnt1>=m)
		{
			ans+=(1LL<<i);
			cnt=0;
			for(int j=1;j<=tot;j++)
			{
				if(check(sy[j],i)==1) ns[++cnt]=sy[j];
			}
			tot=cnt;
			for(int j=1;j<=tot;j++)
			{
				sy[j]=ns[j];
			}
		}
	}
	write(ans);
	
	return 0;
}
/*
4 2
3 15 12 12

12

5 3
31 3 1 15 7

7
*/
