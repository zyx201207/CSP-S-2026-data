#include <iostream>
using namespace std;
const int N=2e5+5;
const int MX=(1<<30)-1;
int n,m;
int a[N],ans;

void dfs(int sum,int pos,int cnt)
{
	if(cnt==m)
	{
		ans=max(ans,sum);
		return ;
	}
	if(pos>n||cnt+(n-pos)+1<m)
	{
		return ;
	}
	dfs(sum,pos+1,cnt);
	dfs((sum&a[pos]),pos+1,cnt+1);
}

void solve_1_to_5()
{
	dfs(MX,1,0);
	cout<<ans;
}

void solve_6()
{
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i]);
	}
	cout<<ans;
}

void solve_7()
{
	ans=MX;
	for(int i=1;i<=n;i++)
	{
		ans=(ans&a[i]);
	}
	cout<<ans;
}

void solve_8_to_10()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,(a[i]&a[j]));
		}
	}
	cout<<ans;
}

void solve_11_to_12()
{
	int minn=MX,mini=0;
	for(int i=1;i<=n;i++)
	{
		int t=a[i],cnt=0;
		while(t)
		{
			if(t&1) cnt++;
			t>>=1;
		}
		if(cnt<minn)
		{
			minn=cnt;
			mini=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=mini)
		{
			ans=(ans&a[i]);
		}
	}
	cout<<ans;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20)
	{
		solve_1_to_5();
	}
	else if(n<=10000)
	{
		if(m==1)
		{
			solve_6();
		}
		else if(m==n)
		{
			solve_7();
		}
		else if(m==2)
		{
			solve_8_to_10();
		}
	}
	else if(m<=N-5)
	{
		if(m==1)
		{
			solve_6();
		}
		else if(m==n)
		{
			solve_7();
		}
		else if(m==n-1)
		{
			solve_11_to_12(); 
		}
	}
	return 0;
}
