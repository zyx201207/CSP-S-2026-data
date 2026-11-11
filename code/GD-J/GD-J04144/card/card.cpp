#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005],ans[500005];
bool vis[500005];
stack<ll> q;
void Put_cards(ll x){
	memset(vis,false,sizeof vis);
	while(!q.empty())q.pop();
	for(ll i=x;i<=n;i++){
		if(vis[a[i]]){
			while(q.top()!=a[i]){
				vis[q.top()]=false;
				q.pop();
			}
		}
		else{
			q.push(a[i]);
			vis[a[i]]=true;
		}
    }
	while(!q.empty()){
		ans[q.top()]++;
		q.pop();
	}		
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++){
    	Put_cards(i);
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<" ";
	}
	return 0;
}
