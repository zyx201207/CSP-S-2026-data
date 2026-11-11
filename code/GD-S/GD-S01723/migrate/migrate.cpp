#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll> 
using namespace std;

bool stMST;
ll c,t,n,d, ans;
ll x[2001000], MAXR[2001000];
// 多测记得清空 
ll dis[2001000], cnt[2001000];

void solve(ll s){
	for(int i=1;i<=n;++i){
		dis[i] = 2e18;
		cnt[i] = 0;
	}
	
	dis[s] = 0;
	cnt[s] = 1;
	for(int i=s;i<=n;++i){
		if(dis[i] >= 2e18) continue;
		for(int j=i+1;j<=MAXR[i];++j){
			if(dis[j] > dis[i]+1){
				dis[j] = dis[i]+1;
				cnt[j] = cnt[i];
			}else if(dis[j] == dis[i]+1){
				cnt[j] += cnt[i];
			}
		}
	}
	
	for(int i=MAXR[s]+1;i<=n;++i){
//			cout<<dis[i]<<' '<<cnt[i]<<'\n';
		if(dis[i] >= 2e18) continue;
		if(cnt[i] == 2){
			++ans;
//			cout<<"#"<<s<<' '<<i<<'\n';
		}
	}
}

bool edMST;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
//	cout<<abs(&edMST-&stMST) / 1024.0 / 1024 <<" MB\n";
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin>>c>>t;
	
	while(t--){
		ans = 0;
		
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		
		ll R = 0;
		for(ll i=1;i<=n;++i){
			R = max(R, i);
			while(R+1 <= n && x[R+1]-x[i] <= d) ++R;
			MAXR[i] = R;
		}
		
		for(int i=1;i<=n;++i){
			solve(i);
		}
		
		cout<<ans<<'\n';
	}
	
	
	return 0;
} 
