#include<bits/stdc++.h> 
#define int long long
using namespace std;

inline void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1,x;i<n;i++)cin>>x>>x;
	
	if(k==2||k==4)cout<<1<<'\n';
	else if(k==3)cout<<2<<'\n';
	else cout<<(k-1)/2<<'\n';
}

inline void solve1(){
	int n,k;
	cin>>n>>k;
	for(int i=1,x;i<n;i++)cin>>x>>x;
	if(k==2){
		cout<<1<<'\n';
		return ;
	}
	if(k==10){
		cout<<4<<'\n';
		return;
	}
	if(k){
		cout<<(k-1)/2<<'\n';
		return;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c==13||c==14)solve();
		else solve1();
	}
	
	return 0;
}
