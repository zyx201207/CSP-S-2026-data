#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100,M=3e5+100;
typedef long long ll;
ll ans,n,a[N],cnt[M],m,k[M];
stack<ll> s,s1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(k[a[i]]==0){
			k[a[i]]=i;
			s.push(a[i]);
		}
		else{
			while(!s.empty()){
				ll z=s.top();
				if(z==a[i]) break;
				cnt[z]+=k[z]-i;k[z]=0;
				s.pop();
			}
		}
	}
	while(!s.empty()){
		ll z=s.top();
		cnt[z]+=k[z];
		s.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}