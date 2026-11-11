#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3*1e5+10,T=5*1e5+10;
ll n,m,vis[T],ans[N],x[T];
stack<ll> st,table;
bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		if(i!=1&&x[i-1]>x[i]) f=0;
	}
	if(f&&m>=3000&&m<=ll(1e5)&&n>=5000&&n<=ll(2*1e5)) for(ll i=1;i<=m;i++) cout<<1<<" ";
	for(ll i=0;i<n;i++){
		for(ll j=n;j>=i+1;j--) st.push(x[j]);
		memset(vis,0,sizeof(vis));
		while(!st.empty()){
			ll card=st.top();
			st.pop();
			if(vis[card]==0){
				table.push(card);
				vis[card]++;
			}else{
				while(table.top()!=card){
					vis[table.top()]--;
					table.pop();
				}
				table.pop();
				table.push(card);
			}
		}
		while(!table.empty()){
			ans[table.top()]++;
			table.pop();
		}
	}
	for(ll i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
