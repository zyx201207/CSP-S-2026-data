#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int N=1e6+5;
vector<int>e[N];
//int dis[N];
int C;
void solve(){
	
	int n,k;
	
	cin>>n>>k;
	if(C==13||C==14){
		
	}
	for(int i=1;i<=n;i++)	e[i]=vector<int>();
	for(int i=1;i<n;i++) {
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int ans=n+5;
	for(int i=0;i<(1ll<<n);i++){
		vector<int>dis(n+5,-1);
		
		queue<int>q;
		int cnt=0,tot=0;
		for(int j=1;j<=n;j++){
			
			if((1<<j-1)&i){
				cnt++;
				bool fl=1;
				for(auto y:e[j])
					if(dis[y]==0)	fl=0;
				tot+=fl;
				q.push(j);
				dis[j]=0;
			}	
		}
		if(cnt!=k||tot>2)	continue;
		int res=0;
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(auto y:e[x]){
				if(dis[y]==-1){
					q.push(y);
					dis[y]=dis[x]+1;
				}	
			}
		}
		for(int j=1;j<=n;j++){
//			cout<<dis[j]<<" ";
			res=max(res,dis[j]);	
		}
//		if(res==1)	cout<<tot<<" ";
		ans=min(res,ans);
	}
	cout<<ans<<'\n';
}
signed main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>C>>t;
	while(t--)
		solve();
	
	
	return 0;
}
