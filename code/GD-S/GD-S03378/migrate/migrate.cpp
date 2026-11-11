#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],lst[2000005],nxt[2000005],siz[2000005],f[2000005][2];
long long s[2000005],cnt;
void read(long long &x)
{
	x=0;
	int w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1; 
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=w;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	int top=0,sta[100];
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while(top--) putchar(sta[top]+'0');
	putchar('\n');
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);read(t);
	while(t--)
	{
		read(n);read(d);
		for(int i=1;i<=n;i++) read(x[i]),siz[i]=0,lst[i]=i,f[i][0]=f[i][1]=0;
		
		long long r=n,ans=0;
		for(int i=n;i>=1;i--)
		{
			while(x[r]-x[i]>d) r--;
			nxt[i]=r;
		}
		for(int i=1;i<=n;i++) siz[nxt[i]]++;
		for(int i=1;i<=n;i++) lst[nxt[i]]=min(lst[nxt[i]],i*1ll);
		for(int i=n-1;i>=1;i--) lst[i]=min(lst[i+1],lst[i]);
		
		for(int i=1;i<=n;i++)
		{
			long long o=i;
			cnt=0;
			s[++cnt]=i;
			while(lst[o]!=o)
			{
				o=lst[o];
				s[++cnt]=o;
				if(cnt>=3) break;
			}
			
			bool bz=1,vis=0;
			for(int j=2;j<=cnt;j++)
			{
				if(min(nxt[s[j]],i*1ll)!=s[j-1])
				{
					vis=0;
					if(bz)
					{
						vis=(min(nxt[s[j]],i*1ll)==s[j-1]+1)&&(min(i*1ll,nxt[s[j-1]+1])==s[j-2]);
					}
					bz=0;
				}
				if(bz)
				{
					if(s[j]+1<s[j-1])
					{
						if(min(nxt[s[j]+1],i*1ll)==s[j-1])
						{
							ans+=siz[s[j]+1];
						}
					}
				}
				
				if(!bz&&vis)
				{
					ans+=siz[s[j]];
				}
			}
			if(lst[o]!=o)
			{
				if(nxt[lst[o]]!=o)
				{
					if((nxt[lst[o]]==o+1)&&(nxt[o+1]==nxt[o]))
					{
						f[o][0]=f[lst[o]][1]+siz[lst[o]];
					}
				}
				else
				{
					f[o][0]=f[lst[o]][0];
					if(lst[o]+1<o)
					{
						if(nxt[lst[o]+1]==o) f[o][0]+=siz[lst[o]+1];
					}
					f[o][1]=f[lst[o]][1]+siz[lst[o]];
				}
				if(bz)ans+=f[o][0];
				else if(!bz&&vis)ans+=f[o][1];
			}
		}
		write(ans);
	}
	return 0;
}
