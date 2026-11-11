#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010];
ll b[300010];
ll c[300010];
ll t[300010];
ll cnt=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	bool flag=1;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
		if(a[i]<a[i-1]) flag=0;
	}if(flag){
		for(ll i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}else{
		stack<ll>stk;
		for(ll i=1;i<=n;i++){
			memset(c,-1,sizeof(c));
			for(ll j=i;j<=n;j++){
				cnt++;
				if(c[a[j]]==-1){
					c[a[j]]=cnt;
					stk.push(a[j]);
				}else{
					ll x=cnt-c[a[j]]-1;
					cnt=c[a[j]];
					while(x--){
						c[stk.top()]=-1;
						stk.pop();
					}
				}
			}while(!stk.empty()){
				t[stk.top()]+=1;
				stk.pop();
			}
		}
		for(ll i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
	}
	return 0;
}

