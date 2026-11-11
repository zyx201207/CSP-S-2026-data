#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x7f7f7f7f;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
inline void write(int x)
{
	if(x==0){
		putchar('0');
		return ;
	}
	if(x<0){
		putchar('-');
		x=-x;
	}
	int tot=0;
	char c[64];
	while(x>0){
		c[tot++]=x%10+'0';
		x/=10;
	}
	while(tot>0)
		putchar(c[--tot]);
}
int c,t,n,d,xi[2000005],dis[2000005],ans,num[2000005];
queue<int>q;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--)
	{
		n=read(),d=read();
		for(int i=1;i<=n;i++)
			xi[i]=read();
		sort(xi+1,xi+1+n);
		for(int j=1;j<=n;j++)
		{
			memset(dis,INF,sizeof(dis));
			memset(num,0,sizeof(num));
			dis[j]=0; 
			q.push(j);
			while(!q.empty())
			{
				int x=q.front();
				q.pop();
				for(int i=1;xi[i]-xi[x]<=d;i++)
				{
					if(i>n)break;
					if(dis[i]>dis[x]+1){
						dis[i]=dis[x]+1;
						num[i]=1;
							q.push(i);
					}
					else if(dis[i]==dis[x]+1){
					num[i]++;
							q.push(i);
					}
				}
			}
			for(int i=1;i<=n;i++)
				if(num[i]==2)
					ans++;
		}
		write(ans);
		putchar('\n');
		ans=0;
	}
	return 0;
}
