#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d,a[2000005],ct[2000005];
void dfs(long long deep,int where,int tar)
{
	if(where==tar)
	{
		ct[deep]++;
		return ;
	}
	else if(where>tar) return ;
	if(abs(a[where]-a[where+1])>d) return ;
	long long ad=(0-(abs(a[where])));
	for(int i=where+1;i<n;i++)
	{
		if(abs(a[where]-a[i])>d) continue;
		ad+=abs(a[i]);
		ad=abs(ad);
		if(d<ad) break;
		dfs(deep+i-where,i,tar);
	}
	return ;
}
bool fd(int tail)
{
	for(int i=0;i<tail;i++)
	{
		if(ct[i]!=0) if(ct[i]==2) return true;
		else return false;
	}
	return false;
}
void solve()
{
	int ans=0;
	memset(ct,0,sizeof(ct));
	memset(a,0,sizeof(a));
	cin>>n>>d;
	for(int i=0;i<n;i++) cin>>a[i];
//	int u=0,v=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			dfs(0,i,j);
			if(fd(j-i+1)) ans++;
		}
	}
	cout<<ans-1<<endl;
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++) solve();
	return 0;
}
