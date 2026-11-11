#include<iostream>
using namespace std;
int c,T,n;
long long d,a[2000005],ans,cnt,Min; 
void dfs(int x,int y,int len)
{
	if(x==y)
	{
		if(Min>len)
			Min=len,cnt=1;
		else if(Min==len)
			cnt++;
		return;
	}
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=d)
			dfs(i,y,len+1);
	}
}
void solve1()
{
	for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			cnt=0,Min=(1ll<<62);
			dfs(l,r,0);
			if(cnt==2)
				ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve2()
{
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n+1;
		while(l+1!=r)
		{
			int mid=(l+r)>>1;
			if(a[mid]-a[i]<=d)
				l=mid;
			else
				r=mid;
		}
		if(r==n+1)
			continue;
		if(r-2==i)
			continue;
		int x=r-2,L=r;
		l=x,r=n+1;
		while(l+1!=r)
		{
			int mid=(l+r)>>1;
			if(a[mid]-a[x]<=d)
				l=mid;
			else
				r=mid;
		}
		int R=l;
		if(r-3==i)
		{
			ans+=(R-L+1); 
			continue;
		}
		l=x-1,r=n+1;
		while(l+1!=r)
		{
			int mid=(l+r)>>1;
			if(a[mid]-a[x-1]<=d)
				l=mid;
			else
				r=mid;
		}
		L=r;
		ans+=max(R-L+1,0);
	}
	cout<<ans<<"\n";
}
void solve3()
{
	int x=1;
	while(x<n&&a[x+1]-a[1]<=d)
		x++;
	if(x<=2||n-(2*x-2)+1<=0)
		cout<<"0\n";
	else
		cout<<n-(2*x-2)+1<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c<=2)
			solve1();
		else if(c==13||c==14)
			solve2();
		else if(c==11||c==12)
			solve3();
	}
	return 0;
}
//use cin && cout
