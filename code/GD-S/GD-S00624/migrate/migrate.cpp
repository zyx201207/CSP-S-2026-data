#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5,oo=52013145201314;
ll Taskid;
ll Q;
ll n,d,a[N],f[N],dis[N],ans;
bool vis[N];
queue<ll>q;
//=====================================================
void BFS(ll st){
	for(int i=st;i<=n;i++)
		dis[i]=oo,f[i]=vis[i]=0;
	dis[st]=0; f[st]=1;
	q.push(st);
	while(!q.empty()){
		ll now=q.front(); q.pop();
		if(f[now]==2) ++ans;
		for(int i=now+1;i<=n;i++){
			if(a[i]-a[now]>d) break;
			if(dis[i]<dis[now]+1) continue;
			f[i]+=f[now]; dis[i]=dis[now]+1;
			if(!vis[i]) q.push(i);
			vis[i]=true;
		}
	} while(!q.empty()) q.pop();
}
//=====================================================
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>Taskid>>Q;
	while(Q--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		for(int i=1;i<=n;i++){
			BFS(i);
//			cout<<i<<":\n";
//			for(int j=i;j<=n;j++)
//				cout<<f[j]<<' ';
//			cout<<"\n\n";
		}
		cout<<ans<<'\n';
	}
	return 0;
}
