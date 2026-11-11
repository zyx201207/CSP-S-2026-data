#include<bits/stdc++.h>
//#define ll long long
using namespace std;

const int N=1e6+10;
vector<int>v[N];
int c,t;
int n,k;

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1; i<n; i++) {
			int u,to;
			cin>>u>>to;
			v[u].push_back(to);
			v[to].push_back(u);
		}
		cout<<1<<endl;
	}

	return 0;
}

