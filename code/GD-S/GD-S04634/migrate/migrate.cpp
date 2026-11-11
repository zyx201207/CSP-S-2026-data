#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5,M=5e3+5,mod=1e9+7,INF=1e18;
int v,T,n,k,a[N],t,shortest;
int bfs(int now,int ed,int dep)//从l到r的最短路径 
{
	if(now==ed) return dep;
	int wz=ed;
	for(int i=now+1;i<=ed+1;i++)
		if(a[i]-a[now]>k)
		{
			wz=i-1;
			break;
		}
	if(wz==now) return -1;
	return bfs(wz,ed,dep+1);
}
void dfs(int now,int ed,int dep)
{
	if(dep>shortest) return ;
	if(now==ed)
	{
		if(dep==shortest) t++;
		return ;
	}
	for(int i=now+1;i<=ed+1;i++)
		if(a[i]-a[now]<=k) dfs(i,ed,dep+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>v>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		a[n+1]=INF;
		int s=0;
		for(int l=1;l<n;l++)
		{
			for(int r=l+1;r<=n;r++)
			{
				t=0,shortest=bfs(l,r,0);
				if(shortest==-1) continue;
				dfs(l,r,0);
				if(t==2) s++; 
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
