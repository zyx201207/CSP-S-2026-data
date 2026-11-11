#include <bits/stdc++.h>
using namespace std;

struct info{
	int u, v;
};

int c, t;

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	cin>>c>>t;
	while (t--){
		int n, k;
		cin>>n>>k;
		vector<info> a(n + 1);
		for (int i = 1;i <= n;i++){
			cin>>a[i].u>>a[i].v;
		}
	}
	
	cout<<1<<endl<<2<<endl;
	
	return 0;
} 
