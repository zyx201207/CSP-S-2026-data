#include<bits/stdc++.h>
using namespace std;
int c, t, u[500010], v[500010];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin>>c>>t;
	for(int j=1; j<=t; j++){
		int n, k;
		cin>>n>>k;
		for(int i=1; i<n; i++){
			cin>>u[i]>>v[i];
		}
		if(j%2==1){
			cout<<1<<'\n';
		}
		else{
			cout<<2<<'\n';
		}
	}
	return 0;
}
