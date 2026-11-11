#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+5;

ll n,m,res=-1;
bool vis[N];

struct Node{
	ll c,s,ss;
}a[N];

bool cmp(Node x,Node y){
	if(x.s!=y.s) return x.s>y.s;
	return x.ss<y.ss;
}

void dfs(ll k,ll now,ll cnt){
	if(k==m){
		res=max(res,cnt);
		return;
	}
	
	for(ll i=now+1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(cnt==0) dfs(k+1,now,a[i].c);
		else dfs(k+1,now,cnt&a[i].c);
		vis[i]=0;
	}
}

void solvenm(){
	cin>>res;
	for(ll i=2;i<=n;i++){
		ll x;cin>>x;
		res&=x;
	}
	cout<<res;
}

void solve2000(){
	for(ll i=1;i<=n;i++) cin>>a[i].c;
	
	dfs(0,0,0);
	
	cout<<res;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(nullptr);

	cin>>n>>m;
	
	if(n==m){
		solvenm();
		return 0;
	}
	if(n<=2000){
		solve2000();
		return 0;
	}
	
	for(ll i=1;i<=n;i++){
		cin>>a[i].c;
		ll cnt=a[i].c;
		while(cnt){
			if(cnt&1) a[i].s++;
			else a[i].ss++;
			cnt>>=1;
		}
	}
	
	sort(a+1,a+n+1,cmp);
	
	res=a[1].c;
	for(ll i=2;i<=m;i++) res&=a[i].c;
	
	cout<<res;

	return 0;
}
