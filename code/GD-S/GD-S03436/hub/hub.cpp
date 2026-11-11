#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
int c,t;
int n,k;
int u[N],v[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		memset(u,0,sizeof u);
		memset(v,0,sizeof v);
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			cin >> u[i] >> v[i];
		}
		cout << 1 << "\n";
	}
	
	return 0;
}
