#include <bits/stdc++.h>
#define let long long
#define rt return
using namespace std;
let c,t,
	n,d,ans,
	mp[1000100];
struct node{
	let id,step;
};
let ck(let a,let b){
	unordered_map<let,let> ma;
	queue<node> qu;
	let mi = 10000000000;
	qu.push({a,0});
	while(!qu.empty()){
		
		node nx = qu.front();
		qu.pop();
		if(nx.id == b) {
			mi = min(mi,nx.step);
			if(nx.step == mi)ma[mi]++;
			continue;
		}
		if(nx.step == mi) continue;
		for(let i = nx.id+1 ;i<=b;i++){
			if(mp[i]-mp[nx.id ]<=d) {
				qu.push({i,nx.step+1});
			}
		}
	}
	if(ma[mi] == 2) rt 1;
	rt 0;
}
void init(){
	cin>>n>>d;
	ans = 0;
	for(let i = 1;i<=n;i++) cin>>mp[i];
	for(let i = 1;i<=n;i++){
		for(let j = i+1;j<=n;j++){
			if(ck(i,j))ans++;
		}
	}
	cout<<ans<<"\n";

}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) init();
	rt 0;
}
