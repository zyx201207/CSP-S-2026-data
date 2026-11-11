#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=5e3+5;
ll a[maxn],dis[maxn][maxn];
int n;
ll d;
ll min_sz[maxn],res[maxn];
void bfs(int u){
	queue<pair<int,int>>q;
	q.push({u,0});
	while(!q.empty()){
		int pos=q.front().first,sz=q.front().second;
//		cout<<u<<' '<<pos<<' '<<sz<<' '<<min_sz[pos]<<' '<<res[pos]<<"\n";
		q.pop();
		if(sz==min_sz[pos])res[pos]++;
		if(sz<min_sz[pos]){
			res[pos]=1;
			min_sz[pos]=sz;
		}
		if(sz>min_sz[pos])continue;
		for(int i=pos+1;i<=n;i++){
			if(dis[pos][i]<=d){
				q.push({i,sz+1});
			}
			else break;
		} 
	}
//	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			min_sz[i]=0x3f3f3f3f;
			res[i]=0;
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=dis[j][i]=a[j]-a[i];
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
//				cout<<i<<' '<<j<<" "<<min_sz[j]<<' '<<res[j]<<"\n";
				if(res[j]==2)ans++;
				min_sz[j]=0x3f3f3f3f;
				res[j]=0;
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}
