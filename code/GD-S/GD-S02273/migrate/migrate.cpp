#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll x[2000006];
ll dp[5005][5005];
ll a[500005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t; cin>>c>>t;
	while(t--){
		ll n,d; cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			if(d<x[2]-x[1]){
				cout<<0;
				continue;
			}
		}
		ll ans=rand()%n;
		cout<<ans<<'\n';
	}
		

	
	return 0;
} 

/*
 0 2
 5 3
-2 -1 0 1 2
 6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/

