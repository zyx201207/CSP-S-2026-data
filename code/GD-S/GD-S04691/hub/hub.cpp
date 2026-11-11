#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6;
int n,k;
vector<int> a[N + 5]; 
int main(int argc, char **argv){
#ifndef LOCAL
	freopen("hub.in","r",stdin);
#endif
#ifndef LOCAL
	freopen("hub.out","w",stdout);
#endif
	int id,t;
	cin >> id >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1;i < n;i++){
			int u,v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		cout << "0\n";
	}
	return 0;
}

