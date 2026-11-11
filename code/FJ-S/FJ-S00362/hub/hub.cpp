#include<bits/stdc++.h> 
using namespace std;

#define ll long long 
const int N=2e6+5;
int u[N],v[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("r","hub.in",stdin);
	freopen("w","hub.out",stdout);
	int op,t;
	cin>>op>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		for(int i=1;i<n;i++) cin>>u[i]>>v[i];
		cout<<n/m-1;
	}
	
	return 0;
}
