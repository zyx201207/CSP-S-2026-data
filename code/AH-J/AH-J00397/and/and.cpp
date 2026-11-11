#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+5;
int a[N],m,cnt,n;
int t[N],ans=0,f=0;
void dfs(int step,int sum)
{
	if(sum>m) return;
	if(step==n+1)
	{
		if(sum==m)
		{
			if(f==0)
			{
				int s=t[1];
				for(int i=2;i<=cnt;i++) s=s&t[i];
				ans=max(ans,s);
			}
			else 
			{
				int s=0;
				if(a[1]!=t[1])s=a[1];
				else s=a[2];
				for(int i=1;i<=n;i++)
				{
					 if(a[i]!=t[1]) s=s&t[i];
				 }
				ans=max(ans,s);
			}
		}
		return ;
	}
	t[++cnt]=a[step];
	dfs(step+1,sum+1);
	t[cnt]=a[step];
	cnt--;
	dfs(step+1,sum);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	int t=a[1];
	for(int i=2;i<=n;i++) 
	{
		cin>>a[i];
		t&=a[i];
	}
	if(n<=2000)
	{
		if(m==n) cout<<t;
		else 
		{
			dfs(1,0);
			cout<<ans;
		}
	}
	else{
		if(m==n-1)
		{
			f=1;
			m=1;
			dfs(1,0);
			cout<<ans;
		}
		else 
		{
			sort(a+1,a+n+1);
			cout<<a[n];
		}
	}
	return 0;
}
