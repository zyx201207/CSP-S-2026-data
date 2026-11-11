#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e5+5;

int n,m;
int ls[N];
int ans=1;
int l=1,r=1;
int cnt;
int cost;



signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>ls[i];
	}
	
	sort(ls+1,ls+n+1);
	
	while(r<=n && l+ans<=n)
	{
		
		if(cost<=m)
		{
			ans=max(ans,cnt+1);
			
			r++;
			
			cnt++;
			
			cost+=(ls[r]-ls[r-1])*cnt;
		}
		
		else
		{
			cost-=r-l;
			
			l++;
			
			cnt--;
		}
	}
	
	cout<<ans;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
