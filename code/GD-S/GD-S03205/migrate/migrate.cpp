#include<bits/stdc++.h>
using namespace std;
const int N=3000009;
int c,T;
int f[5009][5009],tj[5009];
long long d,x[N],n;
bool bz[N];
void dg(int now,int i,int sum)
{
	if(bz[now]) return ;
	tj[now]++; if(tj[now]>2) bz[now]=1;
	for(int j=now+1;x[j]-x[now]<=d&&j<=n;j++)
	{
		if(!bz[j]&&sum+1==f[i][j]) dg(j,i,sum+1);
	}
}
void read(long long &x)
{
	char ch=getchar(); 
	int f=1; x=0;
	while(ch!='-'&&(ch<'0'||'9'<ch))
		ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while('0'<=ch&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	if(f==-1) x=-x;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			read(x[i]);
		if(c<=10)
		{
			for(int i=1;i<=n;i++)
			{
				int prep=i,sum=1;
				f[i][i]=0;
				for(int j=i+1;j<=n;j++)
				{
					if(x[j]-x[j-1]>d) 
					{
						for(int k=j;k<=n;k++)
							f[i][k]=2147483647;
						break;
					}
					if(x[j]-x[prep]>d) prep=j-1,sum++;
					f[i][j]=sum;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++) tj[j]=0,bz[j]=0;
				dg(i,i,0);
				for(int j=i+1;j<=n;j++)
					if(tj[j]==2) 
						ans++;
			}
			printf("%d\n",ans);
		}
		else if(c<=12)
		{
			long long cha=x[2]-x[1];
			long long chushu=d/cha;
			if(chushu<=0||d==cha) printf("0\n");
			else printf("%lld\n",max(0ll,n-chushu-chushu+1));
		}
	}
	return 0;
}
