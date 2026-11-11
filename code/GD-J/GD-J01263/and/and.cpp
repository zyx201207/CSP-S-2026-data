#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+10;
struct aa{ll son[2],dep,cnt,own;}tr[N*40];
ll n,m,tot,ans,v[N*40];
void build(ll x){
	ll u=0;
	string s="";
	while(x){
		if(x%2) s="1"+s;
		else s="0"+s;
		x/=2;
	}
	while(s.size()<30) s="0"+s;
	for(ll i=0;i<s.size();i++){
		ll k=s[i]-'0';
		if(!tr[u].son[k]) tr[u].son[k]=++tot;
		tr[tr[u].son[k]].dep=tr[u].dep+1;
		u=tr[u].son[k];
		tr[u].own=k;
		tr[u].cnt++;
	}
}
void bfs(ll root){
	ll sum=-1;
	queue<ll> q;
	q.push(root);
	while(!q.empty()){
		ll sum1=0;
		vector<ll> stk;
		while(tr[q.front()].dep==sum+1){
			ll u=q.front();q.pop();
			if(v[u]) continue;
			if(tr[u].own==1) sum1+=tr[u].cnt;
			else stk.push_back(u);
			if(tr[u].son[1])q.push(tr[u].son[1]);
			if(tr[u].son[0])q.push(tr[u].son[0]);
		}
		ans*=2;
		if(sum1>=m){
			for(ll t:stk){
				v[tr[t].son[1]]=1;
				v[tr[t].son[0]]=1;
			}
			ans++;
		}
		sum++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		int x;
		cin>>x;
		build(x);
	}
	bfs(0);
	cout<<ans;
	return 0;
}
