#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll a[5*N],t[3*N],l[3*N];
bool check(ll n){
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]) return false;
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	if(n<=1000){
		for(int i=1;i<=n;i++){
			stack<ll> s;
			memset(l,0,sizeof(l));
			for(int j=i;j<=n;j++){
				if(!l[a[j]]){
					l[a[j]]=a[j];
					s.push(a[j]);
				}else{
					while(!s.empty()&&s.top()!=a[j]){
						l[s.top()]=0;
						s.pop();
					}
				}
			}
			while(!s.empty()){
				t[s.top()]++;
				s.pop();
			}
		}
	}else if(check(n)){
		for(int i=1;i<=n;i++) t[a[i]]=i;
	}else{
		ll k=0;
		for(int i=1;i<=n;i++){
			a[i]=a[i-k];
			if(a[i]==a[i+1]) k++;
		}
		for(int i=1;i<=n;i++){
			stack<ll> s;
			memset(l,0,sizeof(l));
			for(int j=i;j<=n;j++){
				if(a[i]==0) continue;
				if(!l[a[j]]){
					l[a[j]]=a[j];
					s.push(a[j]);
				}else{
					while(!s.empty()&&s.top()!=a[j]){
						l[s.top()]=0;
						s.pop();
					}
				}
			}
			while(!s.empty()){
				t[s.top()]++;
				s.pop();
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%lld ",t[i]);
	return 0;
}
