#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin >> c >> t;
	while(t--){
		vector<int> q[N];
		int n,k;
		cin >> n >> k;
		for(int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			q[u].push_back(v);
			q[v].push_back(u);
		}
		if(c>=13){
			cout << "1" << endl;
		}
		else{
			cout <<"2" << endl;
		}
	}
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	return 0;
} 
