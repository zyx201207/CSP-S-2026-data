#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,a[N],ans[N],s[N],to[N],cnt;
void solve(int x,int y)
{
	cnt=0;
	for(int i=x;i<=y;i++)
	{
		int k=a[i];
		if(!to[k])
		{
			cnt++;
			s[cnt]=k;
			to[k]++;
		}
		else
		{
			while(to[k])
			{
				to[s[cnt] ]--;
				s[cnt]=0;
				cnt--;
			}
			cnt++;
			s[cnt]=k;
			to[k]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(to[i])
		{
			ans[i]++;
		}
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(s,0,sizeof(s) );
		memset(to,0,sizeof(to) );
		cnt=0;
		solve(i,n);
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	} 
	return 0;
}
