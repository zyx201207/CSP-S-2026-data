#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define uint unsigned long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define debug() cout<<"come here\n"
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		f=(ch=='-'?-1:f);
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
void writech(int x,char ch)
{
	write(x);
	putchar(ch);
}
int a[2000005],nxt[2000005],nnxt[2000005],pre[2000005],suf[2000005],last[2000005],dis[5005],cnt[5005];
signed main()
{
//	system("fc migrate4.ans migrate.out"); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),T=read();
	while(T--)
	{
		int n=read(),d=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			nxt[i]=nnxt[i]=pre[i]=suf[i]=last[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			int l=i,r=n,zuiyuan=0;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(a[mid]-a[i]<=d)zuiyuan=mid,l=mid+1;
				else r=mid-1;
			}
			nxt[i]=zuiyuan;
//			cout<<nxt[i]<<' ';
		}
//		puts("");
//		int ct=0;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				dis[j]=INF;
//				cnt[j]=0;
//			}
//			cnt[i]=1;
//			dis[i]=0;
//			q.push(i);
//			while(q.size())
//			{
//				int u=q.front();
//				q.pop();
//				for(auto v:e[u])
//				{
//					if(dis[v]>dis[u]+1)
//					{
//						dis[v]=dis[u]+1;
//						q.push(v);
//					}
//					if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
//				}
//			}
//			for(int j=i;j<=n;j++)
//			{
//				if(cnt[j]==2)
//				{
//					ct++;
//				}
//			}
//		}
//		writech(ct,'\n');
//		puts("");
		int ans=0,mx=0;
		int cur;
		vector<int> vc;
		for(int i=n;i>=1;i--)
		{
			if(nxt[i]!=nxt[i-1])
			{
				suf[i]=suf[nxt[i]]+1+(nxt[i]-nxt[i-1]-1);
			}
			else suf[i]=1;
		}
		for(int i=1;i<=n/2;i++)
		{
			swap(a[i],a[n-i+1]);
		}
		for(int i=1;i<=n;i++)
		{
			int l=i,r=n,zuiyuan=0;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(a[i]-a[mid]<=d)zuiyuan=mid,l=mid+1;
				else r=mid-1;
			}
			nxt[i]=zuiyuan;
		}
//		puts("");
		for(int i=n;i>=1;i--)
		{
			if(nxt[i]!=nxt[i-1])
			{
				pre[n-i+1]=pre[n-nxt[i]+1]+1+(nxt[i]-nxt[i-1]-1);
			}
			else pre[n-i+1]=1;
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<pre[i]<<' ';
//		}
//		puts("");
		for(int i=1;i<=n/2;i++)
		{
			swap(a[i],a[n-i+1]);
		}
		for(int i=1;i<=n;i++)
		{
			int l=i,r=n,zuiyuan=0;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(a[mid]-a[i]<=d)zuiyuan=mid,l=mid+1;
				else r=mid-1;
			}
			nxt[i]=zuiyuan;
		}
		for(int i=1;i<=n;i++)
		{
			int l=nxt[max(nxt[i]-2,i)]+1,r=nxt[nxt[i]-1];
			if(nxt[i]==i)continue;
			ans+=max(0ll,r-l+1);
//			cout<<i<<' '<<l<<' '<<r<<'\n';
			if(l>r||r<=mx)continue;
			nnxt[i]=r;
			mx=r;
			last[r]=i;
//			cout<<r<<' '<<i<<'\n';
		}
//		puts("");
//		cout<<"ans"<<ans<<'\n';
		mx=0;
		for(int i=1;i<=n;i++)
		{
			int l=nxt[max(nxt[i]-2,i)]+1,r=nxt[nxt[i]-1];
			if(nxt[i]==i)continue;
//			cout<<i<<' '<<last[r]<<' '<<nnxt[i]<<'\n';
			if(last[r]==i)
			{
				ans+=(pre[i]-1)*(r-l+1);
//				cout<<i<<' '<<pre[i]<<'\n';
			}
		}
//		puts("");
		for(int i=1;i<=n;i++)
		{
//			cout<<i<<' '<<pre[i]<<' '<<suf[i]<<' '<<nnxt[i]<<'\n';
			if(nnxt[i]!=0)ans+=pre[i]*suf[nnxt[i]]-pre[i]-suf[nnxt[i]]+1;
		}
//		cout<<"ans"<<ans<<'\n';
		for(int i=1;i<=n/2;i++)
		{
			swap(a[i],a[n-i+1]);
		}
		for(int i=1;i<=n;i++)
		{
			nxt[i]=nnxt[i]=last[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			int l=i,r=n,zuiyuan=0;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(a[i]-a[mid]<=d)zuiyuan=mid,l=mid+1;
				else r=mid-1;
			}
			nxt[i]=zuiyuan;
//			cout<<nxt[i]<<' ';
		}
//		puts("");
		for(int i=1;i<=n;i++)
		{
			int l=nxt[max(nxt[i]-2,i)]+1,r=nxt[nxt[i]-1];
			if(nxt[i]==i)continue;
//			cout<<i<<' '<<l<<' '<<r<<'\n';
			if(l>r||r<=mx)continue;
			nnxt[i]=r;
			mx=r;
			last[r]=i;
		}
//		puts("");
		mx=0;
		for(int i=1;i<=n;i++)
		{
			int l=nxt[max(nxt[i]-2,i)]+1,r=nxt[nxt[i]-1];
			if(nxt[i]==i)continue;
//			cout<<i<<' '<<last[r]<<' '<<nnxt[i]<<'\n';
			if(last[r]==i)
			{
				ans+=(suf[n-i+1]-1)*(r-l+1);
//				cout<<i<<' '<<pre[i]<<'\n';
			}
		}
		writech(ans,'\n');
	}
	return 0;
}

