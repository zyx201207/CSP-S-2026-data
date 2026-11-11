#include <bits/stdc++.h>
using namespace std;
#define int long long 
int c,T,n,dis[5005][5005],dis2[5005][5005],a[2000005];
vector<int> g[2000005];
void bfs(int u)
{
	queue<int> q;
	q.push(u);
	dis[u][u]=0,dis2[u][u]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int v:g[t]){
			if(dis[u][v]==-1){
				dis[u][v]=dis[u][t]+1;
				dis2[u][v]=dis2[u][t];
				q.push(v);
			}
			else if(dis[u][v]==dis[u][t]+1){
				if(dis2[u][v]!=INT_MAX)
				{
					dis2[u][v]+=dis2[u][t];
					if(dis2[u][v]>2)dis2[u][v]=INT_MAX;
				}
			}
		}
	}
}
int k;
int qry(int x){
	int l=1,r=n;
	int mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(c!=0&&c<=10){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=-1;
				dis2[i][j]=0;
				if(abs(a[i]-a[j])<=k)g[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++) bfs(i);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)ans=ans+(dis2[i][j]==2);
		}
		cout<<ans<<'\n';
	}else if(c<=12){
		int d=a[2]-a[1];
		k=k/d;
		if(k==0||k==1||k>n/2)cout<<0<<'\n';
		else{
			int cs=n%2+1;
			int cha=n/2-k;
			cout<<cha*2+cs<<'\n';
		}
	}else {
		map<int,int> f;
		int j=0,ans=0;
		for(int i=1;i<=n;i++){
			while(a[j+1]+k<=a[i]-k)f[qry(a[j+1]+k)]--,j++;
			ans=ans+f[qry(a[i]-k-1)+2];
		}
		cout<<ans<<endl;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
