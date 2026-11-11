#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+10;
int n,m,a[MAXN],ans,best[MAXN];
mt19937 s(8632946523^0x83639824568fff);
void dfs(int x,int andd,int now)
{
	if(x>n)
	{
		if(now==m) ans=max(ans,andd);
		return ;
	}
	if(n-x+1-(m-now)<0) return ;
	if(andd<ans) return ;
	if(now>m) return ;
	if(now<m) dfs(x+1,andd&a[x],now+1);
	dfs(x+1,andd,now);
}
int work()
{
	int tmp=a[1];
	for(int i=2;i<=m;i++) tmp&=a[i];
	return ans=max(ans,tmp); 
}
void SA()
{
	cout<<1;
	double T=1000;
	int tmp=ans;
	while(T>1e-3)
	{
		int x=s()%n+1,y=s()%n+1;
		swap(a[x],a[y]);
		int now=work();
		if(now>tmp)
		{
			for(int i=1;i<=n;i++) best[i]=a[i];
		}
		if(now>tmp||exp((tmp-now)*1.0/T)>s()%998244353*1.0/998244353) tmp=now;
		else
		{
			for(int i=1;i<=n;i++) a[i]=best[i];
			tmp=work();
		}
		T*=0.99;
	}
	for(int i=1;i<=3000;i++)
	{
		int x=s()%n+1,y=s()%n+1;
		swap(a[x],a[y]);
	}
	int now=work();
	if(now>tmp) for(int i=1;i<=n;i++) best[i]=a[i];
}
signed main(  )
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
	if(m==1)
	{
		int ma=0;
		for(int i=1;i<=n;i++) ma=max(ma,a[i]);
		cout<<ma;
		return 0;
	}
	if(m==2&&n<=10000)
	{
		int ma=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				ma=max(a[i]&a[j],ma);
			}
		cout<<ma;
		return 0; 
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	if(n<=30)
	{
		dfs(1,(1ll<<32)-1,0);
		cout<<ans;
		return 0;
	}
	if(maxx<4)
	{
		int sum[5];
		for(int i=1;i<=n;i++) sum[a[i]]++;
		if(sum[3]!=0)
		{
			m-=sum[3];
			if(m<=0) cout<<3;
			else
			{
				m-=sum[2];
				if(m<=0) cout<<2;
				else
				{
					m+=sum[2];
					m-=sum[1];
					if(m<=0) cout<<1;
					else cout<<0;
				}
			}
			return 0;
		}
		if(sum[2]!=0)
		{
			m-=sum[2];
			if(m<=0) cout<<2;
			else
			{
				m+=sum[2];
				m-=sum[1];
				if(m<=0) cout<<1;
				else cout<<0;
			}
			return 0;
		}
		if(sum[1]!=0)
		{
			m-=sum[1];
			if(m<=0) cout<<1;
			else cout<<0;
			return 0;
		}
		cout<<0;
		return 0;
	}
	work();
	while((double)(clock()*1.0/CLOCKS_PER_SEC)<=0.85) SA();
	cout<<ans;
}
