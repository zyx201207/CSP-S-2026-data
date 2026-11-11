#include<bits/stdc++.h>
#define ll long long
#define psb push_back
using namespace std;
const ll N=5e3+5,inf=(ll)1e18;
ll n,d,C,T,ans=0;
ll a[N],dis[N],cnt[N];
vector<ll> ma[N];
queue<int> q;
void solve(){
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])<=d){
				ma[i].psb(j);
			}
		}
	}
	for(ll st=1;st<n;st++){
		for(ll i=st;i<=n;i++){
			dis[i]=inf;
			cnt[i]=0;
		}
		dis[st]=0;
		cnt[st]=1;
		while(!q.empty()) q.pop();
		q.push(st);
		while(!q.empty()){
			ll x=q.front();
			q.pop();
			for(ll y:ma[x]){
				if(dis[y]>dis[x]+1){
					dis[y]=dis[x]+1;
					cnt[y]=cnt[x];
					q.push(y);
				}else if(dis[y]==dis[x]+1){
					cnt[y]=min(3LL,cnt[x]+cnt[y]);
				}
			}
		}
		for(ll i=st+1;i<=n;i++){
			if(cnt[i]==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
void solve2(){
	ll a1,a2;
	cin>>a1>>a2;
	ans=0;
	for(ll i=3,x;i<=n;i++){
		cin>>x;
	}
	ll p=abs(a2-a1);
	ll t=d/p;
	t=min(t,n-1);
	if(t<=1) cout<<"0\n";
	else{
		if((n-t-1)>0) ans=(n-t-1);
		cout<<ans<<"\n";
	}
}
void init(){
	ans=0;
	for(ll i=1;i<=n;i++){
		vector<ll> vls;
		ma[i].swap(vls);
	}
	memset(a,0,sizeof(a));
	memset(cnt,0,sizeof(cnt));
	memset(dis,0,sizeof(dis));
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		if(n<=5000){
			solve();
			init();
		}else {
			solve2();
		}
	}
	return 0;
}
