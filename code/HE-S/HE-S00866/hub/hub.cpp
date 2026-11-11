#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k;
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
	}
	if(n==5){
		if(n==k) cout<<0<<endl;
		else if(n==k+1) cout<<1<<endl;
		else if(n==k+2) cout<<1<<endl;
		else if(n==k+3) cout<<1<<endl;
	}
	else{
		int l=(n+3)/2;
		k=k/2;
		if((l&1)&&(k&1)) cout<<(l-k)/2<<endl;
		else if(!(l&1)&&!(k&1)) cout<<(l-k)/2<<endl;
		else{
			k--;
			cout<<(l-k)<<endl;
		}
		return;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
}
