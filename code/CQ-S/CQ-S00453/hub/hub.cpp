#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back

namespace kanade
{
	ll read()
	{
		ll ans=0,fs=1;
		char ch=getchar();
		while(ch<'0'||ch>'9')
		{
			if(ch=='-')fs=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			ans=ans*10+ch-'0';
			ch=getchar();
		}
		return ans*fs;
	}
	
	
	struct edge
	{
		int to,ne;
	}e[4000010];
	int H[2000010];
	int cnt=1;
	
	void add(int a,int b)
	{
		e[++cnt].to=b;
		e[cnt].ne=H[a];
		H[a]=cnt;
	}
	
	int n,k;
	int T[100010],dis[100010];
	int bcj[100010];
	
	int find(int x)
	{
		while(bcj[x]!=x)
		{
			x=bcj[x]=bcj[bcj[x]];
		}
		return x;
	}
	
	namespace sub1
	{
		int chk()
		{
			int now=n;
			for(int i=2;i<=cnt;i+=2)
			{
				int a=e[i].to,b=e[i^1].to;
				if(T[a]&&T[b])now--;
			}
			return now;
		}
		
		int res=1e9;
		void dfs(int u,int fa,int d)
		{
			if(T[u])
			{
				res=min(res,d);
				return ;
			}
			for(int i=H[u];i;i=e[i].ne)
			{
				int v=e[i].to;
				if(v==fa)continue;
				dfs(v,u,d+1);
			}
		}
		
		int sol()
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				res=1e9;
				dfs(i,0,0);
				ans=max(ans,res);
			}
//			if(ans==1)
//			{
//				for(int i=1;i<=n;i++)cout<<T[i]<<' ';
//				cout<<sub1::chk()<<endl;
//			}
			return ans;
		}
	
	}
	
	int ans=1e9;

	void dfs(int u,int a)
	{
		if(u>n||!a)
		{
			if(!a)
			{
				if(sub1::chk()>n-k+2)return ;
				ans=min(ans,sub1::sol());
			}
			return ;
		}
		T[u]=0;
		dfs(u+1,a);
		T[u]=1;
		dfs(u+1,a-1);
		T[u]=0;
	}

	int main()
	{
		int c=read(),t=read();
		while(t--)
		{
			n=read(),k=read();
			cnt=1;
			for(int i=1;i<=n;i++)H[i]=0;
			for(int i=1;i<n;i++)
			{
				int a=read(),b=read();
				add(a,b),add(b,a);
			}
			ans=1e9;
			dfs(1,k);
			cout<<ans<<'\n';
		}
		return 0;
	}
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	kanade::main();
	return 0;
}

//就数你就数你就数你

