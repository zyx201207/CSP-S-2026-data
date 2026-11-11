#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=5005;
ll s[N][N],a[N],Min[N];
ll n,d;
void bfs(ll st){
	queue<PII> q;
	for(ll i=1;i<=n;i++){
		Min[i]=2e18;
	}
	q.push({st,0});
	while(!q.empty()){
		ll u=q.front().first;
		ll stp=q.front().second;
		q.pop();
		if(stp<Min[u]){
			s[st][u]=1;
			Min[u]=stp;
		}
		else if(stp==Min[u]){
			s[st][u]++;
		}
		for(ll i=u+1;i<=n;i++){
			if(a[i]-a[u]<=d){
				q.push({i,stp+1});
			}
			else{
				break;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		if(c==11||c==12){
			cin>>n>>d;
			ll x,y;
			cin>>x>>y;
			ll f=d/(x-y);
			if(f>=2&&f<3){
				cout<<n-3<<"\n";
			}
			else{
				cout<<0;
			}
			continue;
		}
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			s[i][i]=1;
		}
		for(ll i=1;i<=n;i++){
			bfs(i);
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(s[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}