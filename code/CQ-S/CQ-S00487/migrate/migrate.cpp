#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int n;
ll d;
ll a[N];
int far[N];
struct node{
	int w;
	ll cnt;
};
node dis[5005][5005];
bool f[5005];
ll ans;
void dfs(int u){
//	cout<<far[1]<<"\n";
	for(int i=u+1;i<=far[u];i++){
		if(!f[i])dfs(i);
		for(int j=i+1;j<=n;j++){
			node cur=dis[i][j];
			if(cur.w+1<dis[u][j].w){
//				cout<<u<<" "<<i<<" "<<j<<"\n";
				dis[u][j].w=cur.w+1;
				dis[u][j].cnt=1;
			}else if(cur.w+1==dis[u][j].w){
				dis[u][j].cnt++;
			}
		}
		dis[u][i].w=1;
		dis[u][i].cnt=1;
//		cout<<u<<" "<<dis[1][4].w<<" "<<i<<"\n";
	}
	if(!f[u]){
		f[u]=1;
		for(int i=u+2;i<=n;i++){
			if(dis[u][i].cnt==2){
				ans++;
//				cout<<u<<" "<<i<<"\n";
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			far[i]=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
//			cout<<far[i]<<" ";
		}
//		cout<<"\n";
		if(c<=10){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					dis[i][j].w=10000000;
				}
			}
			dfs(1);
//			cout<<dis[2][4].w<<" "<<dis[3][4].w<<" "<<dis[1][4].w<<"\n";
			cout<<ans<<"\n";
			ans=0;
			for(int i=1;i<=n;i++){
				f[i]=0;
			}
		}else{
//			cout<<00000<<"\n";
			ll cha=a[2]-a[1];
			if(d<2*cha){
				cout<<0<<"\n";
			}else if(d>=2*cha){
				cout<<n-d/cha+1<<"\n";
			}
		}
	}
	return 0;
} /*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
