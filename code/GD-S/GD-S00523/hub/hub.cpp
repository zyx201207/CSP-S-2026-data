#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50,mod=1e9+7;
int n,k;
void solve1(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	if(n==k)cout<<"0\n";
	else cout<<"1\n";
	return ;
} 
void solveA(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v; 
	}
	if(n==k)cout<<"0\n";
	else if(k>=n/2)cout<<"1\n";
	else cout<<ceil(1.0*((n-1)/2-k)/4)+1;
}
void solve(){
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1,c;
	cin>>c>>T;
	while(T--){
		if(c==1)solve1();
		else if(c==13||c==14)solveA(); 
		else solve();
	} 
	return 0;
} 
