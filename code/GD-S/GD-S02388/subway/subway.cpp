#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[50];
int a[50][50],t[50][50];
void solve(){
	
}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		for(int j = 1;j <= k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		solve();
	}
}
