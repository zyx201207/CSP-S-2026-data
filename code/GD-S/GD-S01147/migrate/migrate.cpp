#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5;
ll c,t,n,d;
ll a[N];
ll cnt,s,ans=0x3f3f3f3f3f3f3f3f;
struct nod{
	ll x;
	ll sum;
};
bool vis[N];
void bfs(ll x,ll y){
	queue<nod> q;
	vis[x]=1;
	q.push({a[x],0});
	while(q.size()){
		nod no=q.front();
		q.pop();
		if(no.x==y)ans=min(ans,no.sum);
		for(ll i=1;i<=d;i++){
			ll ne=no.x+i;
			if(!vis[ne]) 
			q.push({x+i,no.sum+1});
		}
	}
}
void dfs(ll x,ll y,ll st){
	if(x>=y){
		if(st==ans)s++;
		return;
	}
	for(ll i=1;i<=d;i++){
		dfs(x+i,y,st+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll ic=1;ic<=t;ic++){
		cin>>n>>d;
	    cnt=0,s=1;
	
	    for(ll j=1;j<=n;j++){
		cin>>a[j];}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
		bfs(i,a[j]);
		
		dfs(i,j,0);
		if(s==2) cnt++;}
	}	
	cout<<cnt<<"\n";
	}
	return 0;
} 
