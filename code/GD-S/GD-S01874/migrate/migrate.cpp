#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+50,INF=2e18+1;
int c,t,ans;
int n,d,a[N];
vector<int> g[N];
int dis[N],cnt[N];
int bfs(int x){
	for(int i=x;i<=n;i++)
		dis[i]=cnt[i]=0;
	queue<pair<int,int> >q;
	q.push({x,0});
	cnt[x]=1;
	while(!q.empty()){
		int t=q.front().first,s=q.front().second;
		q.pop();
		for(int y:g[t]){
			if(!dis[y]){
				dis[y]=s+1;
				cnt[y]=cnt[t];
				q.push({y,dis[y]});
			}
			else if(s+1==dis[y])
				cnt[y]+=cnt[t];
		}
	}
	int sum=0;
	for(int i=x+1;i<=n;i++)
		if(cnt[i]==2)
			sum++;
//	cout<<x<<":";
//	for(int i=x+1;i<=n;i++)
//		cout<<cnt[i]<<' ';
//	cout<<"\n";
//	for(int i=x+1;i<=n;i++)
//		cout<<dis[i]<<' ';
//	cout<<"\n";
	return sum;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			g[i].clear();
		int k=INF;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(k==INF&&i==2)
				k=a[i]-a[i-1];
			if(k!=INF&&k!=-INF&&a[i]-a[i-1]!=k)
				k=-INF;
		}
		if(k==0){
			cout<<0<<"\n";
			continue;
		}
		if(k!=-INF){
			int h=d/abs(k);
			if(h<=1||2*h-1>n-1)
				cout<<0<<'\n';
			else
				cout<<n-2*h+1<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d)
					g[i].push_back(j);
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=bfs(i);
		cout<<ans<<"\n";
	}
	return 0;
}
