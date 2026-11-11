#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],c[300005];
bool b[500005];
stack<ll> q;
void solve(ll i){
	memset(b,0,sizeof(b));
	for(;i<=n;i++){
		while(b[a[i]] and q.top()!=a[i]){
			b[q.top()]=0;
			q.pop();
		}
		if(q.top()!=a[i]){
			q.push(a[i]);
			b[a[i]]=1;
		}
	}
	while(!q.empty()){
		c[q.top()]++;
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		solve(i);
	}
	for(ll i=1;i<=m;i++) cout<<c[i]<<' ';
	fclose(stdin);
	fclose(stdout);
    return 0;
}
