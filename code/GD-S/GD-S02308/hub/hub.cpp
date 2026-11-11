#include <bits/stdc++.h>
#define endl '\n'
#define lint long long
using namespace std;

int n,k;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int C,T;
	cin >> C >> T;
	while(T--){
		cin >> n >> k;
		int x,y;
		for(int i = 1; i < n; i++){
			cin >> x >> y;
		}
		cout << n/2-k/2 << endl;
	}
	
	return 0;
}
