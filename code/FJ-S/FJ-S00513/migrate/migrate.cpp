#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=50010;
ll c,t,n,d;
ll x[N],k[N],sum[N];
vector<ll>p[N];
bool g[N];
queue<ll>q;
ll cut=0;
int bfs(ll s){
	memset(g,true,sizeof(g));
	memset(k,0,sizeof(k));
	memset(sum,0,sizeof(sum));
	while(!q.empty())
		q.pop();
	q.push(s);
	k[s]=0;
	g[s]=false;
	while(!q.empty()){
		ll t=q.front();
		q.pop();
		for(ll i=0;i<p[t].size();i++){
			ll w=p[t][i];
			if(g[w]||((!g[w])&&k[w]==k[t]+1))sum[w]++;
			if(!g[w])continue;
			k[w]=k[t]+1;
			g[w]=false;
			q.push(w);
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
		if(sum[i]==2&&i!=s)
			ans++;
	//for(int i=1;i<=n;i++)	
	//	cout<<sum[i]<<' ';
	//cout<<endl;
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
			while(!p[i].empty())
				p[i].pop_back();
		for(ll i=1;i<=n;i++)
			cin>>x[i];
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n&&x[j]-x[i]<=d;j++)
				p[i].push_back(j),p[j].push_back(i);
		}
		cut=0;
		for(ll i=1;i<=n;i++){
			cut+=bfs(i);
		}
		cout<<cut/2<<endl;
	}
	return 0;
}
