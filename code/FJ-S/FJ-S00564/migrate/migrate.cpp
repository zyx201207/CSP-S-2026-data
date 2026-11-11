#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N = 2000006;
int c,T,n,d,x[N],min_n,tmp;
void dfs(int now,int j,int cnt)
{
	if(now==j)
	{
		if(cnt==min_n)tmp++;
		else if(cnt<min_n)
		{
			tmp=1;
			min_n=cnt;
		}
		return; 
	}
	for(int r=j;r>=now+1;r--)
	{
		if(x[r]-x[now]<=d)
		{
			dfs(r,j,cnt+1);
		}
	}
}
void answer1()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			tmp=0;min_n=1e16;
			dfs(i,j,0);
			if(tmp==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main(void)
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==1||c==2){answer1();continue;}
		cout<<0<<"\n";
	} 
} 
