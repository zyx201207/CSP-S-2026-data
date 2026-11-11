#include<bits/stdc++.h>
using namespace std;
using ll=long long; 
#define _for(i,a,b) for(int i=a,IM=b;i<=IM;i++)

const int N=5e5+9,inf=1e9+9;
vector<int> ve[N];

void solve () {
	int n,k; cin>>n>>k;
	_for(i,1,n-1) {
		int x,y; cin>>x>>y;
		ve[x].push_back(y),ve[y].push_back(x);
	}
	
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t; cin>>c>>t; while(t--) 
	solve();
	return 0;
}
/*
5 5
1 2 4 8 9
*/
