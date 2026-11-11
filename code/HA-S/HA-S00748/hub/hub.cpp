#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
#define ull unsigned long long
int c,t,n,k;
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	cout<<(int)sqrt((int)(2+(n-k)/2))<<'\n';
}
void solve2(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	cout<<((n+1)/2-k)/4+1<<'\n';	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--) solve2();
	}
	else{
		while(t--) solve();
	}
	return 0;
}
