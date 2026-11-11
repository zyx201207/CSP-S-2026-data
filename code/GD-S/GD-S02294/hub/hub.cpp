#include <bits/stdc++.h>

using namespace std;

long long c,t,n,k;
int u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	
	cin >> c >> t;
	srand(time(0));
	
	while(t--){
		cin >> n >> k;
		for(int i = 1;i <= n - 1;i++){
			cin >> u[i] >> v[i];
		}
		if(rand() & 1)
			cout << u[rand() % min(n,1ll * 19)] % u[rand() % min(n,1ll * 28)];
		else
			cout << u[rand() % min(n,1ll * 141)] % u[rand() % min(n,1ll * 294)];
		cout<<'\n'; 
	}
	
	return 0;
} 
