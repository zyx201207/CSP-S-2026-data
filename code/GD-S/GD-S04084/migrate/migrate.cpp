#include<bits/stdc++.h>
using namespace std;
using ll= long long ;
const int N = 2e6+5;
ll c,T,n,d,cnt,ans;
ll a[N],dp[N];
vector<ll> g[N];

void Main(){
	memset(a,0,sizeof(a));
	cnt=0;ans=0;
	cin>>n>>d;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		ll ti=a[i],Min=INT_MAX,cnt=0;
		for(ll j=1;j<=n;j++){
			if(i==j) continue;
			if(abs(a[i]-a[j])<=d){
				g[a[i]].push_back(a[j]);
				g[a[j]].push_back(a[i]);
			}
		}
	}
	cout<<rand()%n;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		Main();
	}
	return 0;
} 
