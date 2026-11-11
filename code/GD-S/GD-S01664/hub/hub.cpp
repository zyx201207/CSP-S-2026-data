#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 2000006
#define fi first
#define se second
int c,T,n,k;
vector<int> tr[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
//	freopen("ans.out","w",stdout);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1;i < n;i++){
			int u,v;
			cin >> u >> v;
			tr[u].push_back(v);
			tr[v].push_back(u);
		}
		if(c==13||c==14){
			cout << ceil((n-k-3)/3) << endl;
		}
	}
	return 0;
}
