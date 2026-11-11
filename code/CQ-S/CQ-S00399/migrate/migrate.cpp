#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int c,t;
int sum[2000005],vis[2000005];
int a[2000005],ans;
vector<int>g[2000005];
inline void bfs(int s){
	for(int i=1;i<=n;i=-~i)vis[i]=0,sum[i]=0;
	sum[s]=1;
	queue<int>p;
	p.push(s);
	while(!p.empty()){
		int u=p.front();
		p.pop();
		for(auto it:g[u]){
			if(!vis[it]){
				vis[it]=vis[u]+1;
				sum[it]=sum[u];
				p.push(it);
			}
			else if(vis[it]==vis[u]+1)sum[it]+=sum[u];
		}
	}
}
inline bool check(int i,int j){
	if(abs(a[j]-a[i])<=m)return true;
	return false;
}
int nex[2000005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			ans=0;
			cin>>n>>m;
			for(int i=1;i<=n;i=-~i)cin>>a[i];
			if(n==1){
				cout<<0;
				continue;
			}
			int x=a[2]-a[1];
			m/=x;
			if(m<2){
				cout<<0<<'\n';
				continue;
			}
			m=2*m-1;
			cout<<max((int)0,n-m)<<'\n';
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			ans=0;
			cin>>n>>m;
			for(int i=1;i<=n;i=-~i)cin>>a[i];
			if(n==1){
				cout<<0;
				continue;
			}
			for(int i=1;i<=n;i=-~i){
				int l=i+1,r=n;
				while(l<=r){
					int mid=(l+r)>>1;
					if(check(i,mid))l=mid+1;
					else r=mid-1;
				}
				nex[i]=l-1;
				for(int j=l;j<=n;j=-~j){
					if(!check(nex[i],j))break;
					if(check(nex[i]-1,j)&&!check(nex[i]-2,j))ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i=-~i)cin>>a[i];
		if(n==1){
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i=-~i){
			g[i].clear();
			for(int j=i+1;j<=n;j=-~j){
				if(a[j]-a[i]<=m)g[i].push_back(j);
				else break;
			}
		}
		for(int i=1;i<=n;i=-~i){
			bfs(i);
			for(int j=i+1;j<=n;j=-~j){
				ans+=(sum[j]==2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
rp++
*/
