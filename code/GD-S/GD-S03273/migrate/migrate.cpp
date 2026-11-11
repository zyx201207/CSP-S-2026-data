#include <bits/stdc++.h>
#define MAXN 2000006
using ll = long long;
using namespace std;
using pii = pair<int,int>; 
int n;
ll d;
ll a[MAXN];
int nxt[MAXN];
int mnv[MAXN],smn[MAXN]; 
bool dbg;
void work(){
	int cur = n;
	int mn = n+1, se = n+1;
	for(int i=n;i>=1;i--){
		while(cur >= 1 && nxt[cur]>=i){
			swap(mn,se); mn=cur;
			cur--;
		}
		mnv[i] = mn; smn[i] = se;
	}
	for(int i=1;i<=n;i++){
		if(nxt[mnv[i]] != i || mnv[i]==i)mnv[i] = 0;
		if(nxt[smn[i]] != i || smn[i]==i)smn[i] = 0;
	}
}
ll dp[MAXN][2];
bool chk(int l,int r){
	if(nxt[l]>=r)return false;
	int p = l, cnt=0;
	while(nxt[p]<r){
		if(nxt[p] == p)return false;
		if(p!=l){
			if(nxt[p-1] == nxt[p]){
				if(p-2>=l && nxt[p-2] == nxt[p])return false;
				cnt++;
			}
		}
		p = nxt[p];
	}
	if(nxt[p-1] >= r)cnt++;
	if(nxt[p-2] >= r)return false;
	//if(cnt==1)cerr<<l<<" "<<r<<"\n";
	return cnt==1;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n+1;i++)mnv[i] = smn[i] = n+1;	
	int r = 1;
	nxt[0]=nxt[n+1]=0;
	for(int i=1;i<=n;i++){
		r = max(r,i);
		while(r<n && a[r+1]-a[i]<=d)r++;
		nxt[i] = r;
	}
	//for(int i=1;i<=n;i++)cerr<<nxt[i]<<" ";
	//cerr<<"\n";
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans += chk(i,j);
		}
	}
	cout<<ans<<"\n";
}
int main(){
#ifndef SVK
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int c,T; cin>>c>>T;
	while(T--)solve();
	return 0;
}


