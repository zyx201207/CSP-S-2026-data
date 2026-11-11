#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5,M=3e5+5;
ll a[N],cnt[M];
bool book[M];
ll n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	
	for(ll i=1;i<=n;i++){
		stack<ll>c;
		for(ll j=i;j<=n;j++){
			if(book[a[j]]){
				while(c.top()!=a[j]){
					book[c.top()]=0;
					c.pop();
				} 
				c.pop();
			}
			c.push(a[j]);
			book[a[j]]=1;//ÈëÕ» 
			
		}
		while(!c.empty()){
			book[c.top()]=0;
			cnt[c.top()]++;
			c.pop();
		}
	}
	for(ll i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
} 
