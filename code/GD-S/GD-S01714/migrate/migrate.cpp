#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+5;
int c,T,n,d,cnt,a[N]; 
int js(int x,int y){
	if(x>=y)return 0;
	int l=x+1,r=y;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]-a[x]<=d)l=mid+1;
		else r=mid-1;
	}
	if(a[l]-a[x]>d)l--;
	return 1+js(l,y);
}
void dfs(int x,int y,int ans,int mb){
	if(x==y)
	{
		if(ans>mb)return;
		cnt++;
		return;
	}
	for(int i=x+1;i<=y&&a[i]-a[x]<=d;i++)dfs(i,y,ans+1,mb);
}
void workx(){
	int x=d/(a[2]-a[1]);
	if(x==1||x==0||x>=n)
	{
		cout<<0<<endl;
		return;
	}
	x*=2;
	cout<<n-x+1<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		bool fg=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])fg=1;
		}
		if(fg==0)
		{
			workx();
			continue;
		}
		int ret=0;
		for(int i=1;i<=n;i++)
		{
			bool fl=0;
			if(a[i+1]-a[i]>d||a[i+2]-a[i+1]>d)fl=1;
			for(int j=i+3;j<=n;j++)
			{
				if(a[j]-a[j-1]>d)fl=1;
				if(fl==1)break;
				int sum=js(i,j);
				cnt=0;
				dfs(i,j,0,sum);
				if(cnt==2)ret++;
			}	
		} 
		cout<<ret<<endl;
	}
	return 0;
}
