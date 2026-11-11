#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define inf 1000000000
int C,n,K;
vector<int>G[N];

int d[N];
queue<int>q;
bool vis[N];
bool check(int mid){
	for(int i=1;i<=n;i++)d[i]=inf,vis[i]=0;
	while(q.size())q.pop();
	
	for(int i=1;i<=n;i++)if(G[i].size()==1)d[i]=0,q.push(i);
	
	int num1=0;
	while(q.size()){
		int x=q.front();q.pop();
		num1++;
		if(d[x]==mid)continue;
		for(int y:G[x]){
			if(d[y]>d[x]+1){
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	
	int num2=0;
	for(int i=1;i<=n;i++)if(d[i]==inf&&!vis[i]){
		num2++;
		if(num2==3)return 0;
		q.push(i);vis[i]=1;
		while(q.size()){
			int x=q.front();q.pop();
			for(int y:G[x])if(d[y]==inf&&!vis[y]){
				q.push(y);
				vis[y]=1;
			}
		}
	}
	
	if(num1==2&&n-num1>K)return 0;
	else if(n-num1-2>K)return 0;
	
	return 1;
}
void solve(){
	for(int i=1;i<=2000000;i++)G[i].clear();
	
	cin>>n>>K;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		G[x].push_back(y);G[y].push_back(x);
	}
	
	int l=1,r=n,ans=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>C>>T;
	while(T--)solve();
	
	return 0;
}
