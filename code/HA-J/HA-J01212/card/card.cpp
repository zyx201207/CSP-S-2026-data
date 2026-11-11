#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=5e5+5;
const ll M=3e5+5;
ll n,m;
ll o[N],last[M],ans[M];
void play(ll x){
	ll i=x;
	while(i<=n){
		if(last[o[i]]>i)	i=last[o[i]];
		else{
			ans[o[i]]++;
			i++;
		}
	}
}
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>o[i];
		if(i>last[o[i]])	last[o[i]]=i;
	}
	for(ll i=1;i<=n;i++)	play(i);
	for(ll i=1;i<=m;i++)	cout<<ans[i]<<" ";
	cout<<'\n';
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	solve();
	return 0;
}
