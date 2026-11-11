#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1000005],ins[1000005],ans[1000005];
stack<ll> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(ins[a[j]]==0) s.push(a[j]),ins[a[j]]=1;
			else{
				while(s.size()>0){
					if(s.top()==a[j]){
						ins[s.top()]=0,s.pop();
						break;
					}
					ins[s.top()]=0;
					s.pop();
				}
				s.push(a[j]),ins[a[j]]=1;
			}
		}
		while(s.size()>0) s.pop();
		for(ll k=1;k<=m;k++) if(ins[k]==1) ans[k]++,ins[k]=0;
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' '; 
	return 0;
}
