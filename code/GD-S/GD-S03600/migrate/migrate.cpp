#include<bits/stdc++.h>
using namespace std;
#define _for(i,x,y,z) for(int i=x;i<=y;i+=z)
#define _for1(i,x,y,z) for(int i=x;i>=y;i-=z)
typedef long long ll;
const int N=2e6+15;
int c,T,n;
ll d,a[N],ans;
ll dis[N],p[N];
bool vis[N];
void f1(int start){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(p,0,sizeof(p));
	dis[start]=0;
	priority_queue<
	pair<ll,ll>,
	vector<pair<ll,ll>>,
	greater<pair<ll,ll>>> q;
	q.push({0,start});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		_for(i,u+1,n,1){
			if(a[i]-a[u]>d)break;
		//	cout<<u<<" "<<i<<"\n";
			if(dis[u]+1<dis[i]&&a[i]-a[u]<=d){
				dis[i]=dis[u]+1;
				p[i]=max(p[u],1LL);
				q.push({dis[i],i});
			}else if(dis[u]+1==dis[i]&&a[i]-a[u]<=d)p[i]+=max(p[u],1LL);
		}
	}/*_for(i,1,n,1)cout<<dis[i]<<" ";
	cout<<"\n";
	_for(i,1,n,1)cout<<p[i]<<" ";
	cout<<"\n\n";*/
}
void solve(){
	ans=0;
	cin>>n>>d;
	_for(i,1,n,1){
		cin>>a[i];
	}_for(i,1,n,1){
		f1(i);
		_for(j,1,n,1)ans+=(p[j]==2);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
}
