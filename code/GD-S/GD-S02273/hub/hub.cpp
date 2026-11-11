#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll x[2000006];
ll a[500005];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t; cin>>c>>t;
	while(t--){
		ll n,d; cin>>n>>d;
		for(int i=1;i<n;i++){
			cin>>x[i]>>a[i];
		}
		cout<<rand()%n<<'\n';
	}
		

	
	return 0;
} 
/*
 0 2
 5 2
 1 2
 2 3
 3 4
 4 5
 10 3
 1 2
 1 3
 2 4
 2 5
 3 6
 3 7
 3 8
 7 9
 9 10


*/

/*
 0 2
 5 3
-2 -1 0 1 2
 6 2
-4 -3 -2 -1 3 6

*/

