#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,d,c,a[2000005],ans,sum,flag[2000005],book[2000005];
int read()
{
    char c=getchar();int x=0,flag=1;
    while(c<'0'||c>'9'){if(c=='-'){flag=-1;}c=getchar();}
    while(c<='9'&&c>='0'){x=x*10+c-'0';c=getchar();}
    return x*flag;
}
void dfs(int x,int y,int s)
{
    if(x==y)
    {
        if(sum>s)
        {
            sum=s;
            flag[sum]=1;
        }
        else if(sum==s)
            flag[sum]++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(abs(a[x]-a[i])<=d&&!book[i])
        {
            book[i]=1;
            dfs(i,y,s+1);
            book[i]=0;
        }
    }
    return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    if(c!=13&&c!=14)
    {
		while(t--)
		{
			n=read();d=read();
			ans=0;
			for(int i=1;i<=n;i++)
				a[i]=read();
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(j==k)
						continue;
					int f=0;
					for(int i=min(j,k)+1;i<=max(k,j);i++)
						if(a[i]-a[i-1]>d)
							f=1;
					for(int i=max(j,k)-1;i>=min(j,k);i--)
						if(a[i+1]-a[i]>d)
							f=1;
					if(f)
						continue;
					memset(book,0,sizeof book);
					sum=INT_MAX;
					book[j]=1;
					memset(flag,0,sizeof flag);
					dfs(j,k,0);
					if(flag[sum]==2)
					{
						ans++;
					}
				}
			}
			printf("%lld\n",ans/2);
		}
	}
	else
	{
		while(t--)
		{
			n=read();d=read();
			ans=0;
			int no;
			for(int i=1;i<=n;i++)			
				a[i]=read();
			for(int i=1;i<=n;i++)
			{
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
				{
					no=i;
					break;
				}
			}
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(j==k)
						continue;
					
					int f=0;
					for(int i=min(j,k)+1;i<=max(k,j);i++)
						if(a[i]-a[i-1]>d)
							f=1;
					for(int i=max(j,k)-1;i>=min(j,k);i--)
						if(a[i+1]-a[i]>d)
							f=1;
					if(f)
						continue;
					memset(book,0,sizeof book);
					sum=2;
					if(j==no||k==no)
					{
						flag[1]=1;
					}
					else
						flag[2]=1;
					book[j]=1;
					memset(flag,0,sizeof flag);
					dfs(j,k,0);
					if(flag[sum]==2)
					{
						ans++;
					}
				}
			}
			printf("%lld\n",ans/2);
	}
    return 0;
}
