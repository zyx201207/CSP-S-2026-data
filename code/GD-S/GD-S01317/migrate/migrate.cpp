#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,m,f[5005][5005],a[5005],go[5005][5005],k[5005][5005],x,ans;
/*ll goo(ll x,ll y)
{
	ll z=__lg(y);
	while(y)
	{
		if((1<<z)&y)
		{
			x=go[z][x];
			y=y-(1<<z);
		}
		z>>=1;
	}
	return x;
}*/
void dfs(ll x,ll y)
{
	if(f[x][y]) return;
	ll z=k[x][y];
	dfs(go[x][1],y);
	f[x][y]=f[go[x][1]][y];
	if(k[go[x][1]-1][y]==k[go[x][1]][y])
	{
		dfs(go[x][1]-1,y);
		f[x][y]+=f[go[x][1]-1][y];
	}
	if(go[x][1]>x+2&&k[go[x][1]-2][y]==k[go[x][1]][y]) f[x][y]=3;
	//if(x==3&&y==8) cout<<x<<" "<<y<<" "<<f[x][y]<<"\n";
	f[x][y]=min(f[x][y],3ll);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		x=1;
		cin>>n>>m;
		//cout<<"---\n";
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			while(m<a[i]-a[x])
			{
				go[x][1]=i-1;
				x++;
				//if(x==i-1) go[x][1]=0;
			}
		}
		for(;x<=n;x++) go[x][1]=n;
		for(int i=1;i<=n;i++) for(int j=i;j<=go[i][1];j++) f[i][j]=1;
		for(int i=2;i<=n;i++) for(int j=1;j<=n;j++) go[j][i]=go[go[j][i-1]][1];
		for(int i=1;i<=n;i++)
		{
			x=1;
			for(int j=i+1;j<=n;j++)
			{
				if(go[i][x]<j) x++;
				if(go[i][x]<j) break;
				k[i][j]=x;
				//cout<<i<<","<<j<<"  "<<x<<"\n";
			}
		}
		/*for(int i=1;i<=n;i++)
		{
			cout<<go[i][1]<<" ";
			for(int j=1;j<=n&&go[i][j];j++) cout<<go[i][j]<<" ";
			cout<<"\n";
		}*/
		for(int i=1;i<=n;i++) for(int j=go[i][1]+1;j<=n;j++)
		{
			if(!k[i][j]) continue;
			if(!f[i][j]) dfs(i,j);
		}
		//for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) go[i][j]=go[i-1][go[i-1][j]];
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		{
			if(go[i][j]!=-1&&f[i][j]==2) ans++;
			f[i][j]=k[i][j]=0;
		}
		cout<<ans<<"\n";
		ans=0;
	}
	
	return 0;
}
/*
-1000000000000000000
-999999999999999997
-999999999999999994
-999999999999999993
-999999999999999992
-999999999999999991
-999999999999999990
-999999999999999989
-999999999999999986
-999999999999999983
*/
