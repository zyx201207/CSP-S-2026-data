#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c,T,n,d,a[N],num,u,v,ans,minn;

void dfs(ll pos,ll cnt)
{
	if(pos==v&&cnt<minn)
	{
		minn=cnt;
		num=1;
		return ;
	}
	if(pos==v&&cnt==minn)
	{
		num++;
		return ;
	}
	if(cnt>=minn)return ;
	for(int i=pos+1;i<=v;i++)
	{
		if(a[i]-a[pos]<=d)
		{
			dfs(i,cnt+1);
		}
		else break;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				num=0;
				minn=2e18;
				u=i,v=j;
				dfs(i,0);
				if(num==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
