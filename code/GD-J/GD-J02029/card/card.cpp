#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' or ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int num[105];
inline void write(int x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	int cnt=0;
	while(x)
	{
		cnt++;
		num[cnt]=x%10;
		x/=10;
	}
	for(int i=cnt;i>=1;i--)
	{
		putchar(num[i]+'0');
	}
}
const int N=5e5+5;
const int M=3e5+5;
int n,m,k;
int a[N],las[M],g[N],ans[M];
priority_queue<int>q;
int s[N],top;
struct node
{
	int x,s;
}b[N];
void solve()
{
	for(int j=1;j<=n;j++)
	{
		top=0;
		for(int i=j;i<=n;i++)
		{
			if(g[i]>=j and las[a[i]]<=top and s[las[a[i]]]==a[i])
			{
				top=las[a[i]];
			}
			else
			{
				top++;
				s[top]=a[i];
				las[a[i]]=top;
			}
		}
		for(int i=1;i<=top;i++)
		{
			ans[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		write(ans[i]);
		putchar(' ');
	}
}
void solve2()
{
	for(int j=1;j<=k;j++)
	{
		top=0;
		for(int i=j;i<=k;i++)
		{
			if(g[i]>=j and las[b[i].x]<=top and s[las[b[i].x]]==b[i].x)
			{
				top=las[b[i].x];
			}
			else
			{
				top++;
				s[top]=b[i].x;
				las[b[i].x]=top;
			}
		}
		for(int i=1;i<=top;i++)
		{
			ans[s[i]]+=b[i].s;
		}
	}
	for(int i=1;i<=m;i++)
	{
		write(ans[i]);
		putchar(' ');
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	bool bz=1,flg=1;
	int sum=0;
	for(int i=1;i<=n;i++)
	{ 
		a[i]=read();
		g[i]=las[a[i]];
		las[a[i]]=i;
		if(a[i]>=3) bz=0;
		if(a[i]<a[i-1]) flg=0;
		if(a[i]!=a[i+1]) sum++;
	}
	if(n<=20000)
	{
		memset(las,0,sizeof(las));
		solve();
		return 0;
	}
	if(bz)
	{
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) ans1++;
			else ans2++;
		}
		if(a[n]==1) cout<<n<<" "<<ans2;
		else cout<<ans1<<" "<<n;
		return 0;
	}
	if(flg)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<las[i]<<" ";
		}
		return 0;
	}
	if(sum<=6000)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])
			{
				b[k].s++;
			}
			else
			{
				k++;
				b[k].x=a[i];
				b[k].s=1;
			}
		}
		for(int i=1;i<=k;i++)
		{
			g[i]=las[b[i].x];
			las[b[i].x]=i;
		}
		memset(las,0,sizeof(las));
		solve2();
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		while(!q.empty() and q.top()>=i)
		{
			q.pop();
		}
		if(q.empty()) ans[a[i]]=min(las[a[i]],ans[a[i]]+i);
		else ans[a[i]]=min(las[a[i]],ans[a[i]]+i-max(g[i],q.top()));
		if(g[i]) q.push(g[i]);
	}
	for(int i=1;i<=m;i++)
	{
		write(ans[i]);
		putchar(' ');
	}
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
