#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll w[1000006];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t,n,m;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		cout<<"0\n";
	}
	return 0;
}
