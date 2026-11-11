#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define in inline
const ll maxn=5e3+5;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll c,t;
ll n,d;
ll x[maxn];
ll dp[maxn][maxn];
ll ans[maxn];
bool b[maxn];
ll _min[maxn];
void bfs(ll d){
	memset(b,0,sizeof(b));
	memset(ans,0,sizeof(ans));
	memset(_min,0,sizeof(_min));
	queue<pair<ll,ll>> q;
	q.push({d,0});
	_min[d]=0;
	ans[d]=0;
	while(!q.empty()){
		ll u=q.front().first;
		ll o=q.front().second;
		q.pop();
		ll r=u+1;
		while(x[r]-x[u]<=d){
			if(!_min[r]){
				_min[r]=o+1;
				ans[r]++;
				q.push({r,o+1});
			}else{
				if(_min[r]==0+1){
					ans[r]++;
				}
			}
			r++;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			dp[i][i]=0;
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;k>=1;k--){
					dp[i][j]=min(dp[i][j],dp[i][k]+1);
				}
			}
		}
		ll cnt=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++){
				if(ans[j]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

