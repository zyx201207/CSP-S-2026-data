#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m;
ll a[N];
ll ans[N],k[N],rd[N],last[N];
bool val[N];
vector<ll>G[N];
queue<ll>q;
//===============================================================
void Topu(){
	for(int i=1;i<=n;i++)
		if(!rd[i]) q.push(i);
	while(!q.empty()){
		ll now=q.front(); q.pop();
		k[now]++;
		for(auto nxt:G[now]){
			k[nxt]+=k[now];
			rd[nxt]--;
			if(!rd[nxt]) q.push(nxt);
		}
	}
}
//===============================================================
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(i==n){
			val[i]=true;
			last[a[i]]=i;
			continue;
		}
		ll lead=last[a[i]];
		if(!lead){ val[i]=true; G[i].push_back(i+1); rd[i+1]++; }
		else{ G[i].push_back(lead); rd[lead]++; }
		last[a[i]]=i;
	}
	Topu();
	for(int i=1;i<=n;i++)
		if(val[i]) ans[a[i]]+=k[i];
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
} 
