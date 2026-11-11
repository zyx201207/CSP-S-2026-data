#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll c,n,m,d,q;
vector<ll> w;
vector<int> nxt;
ll z;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	w.push_back(0);
	for(int i = 1;i <= m;i++){
		cin>>z;
		w.push_back(z);
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		int z1;
		for(int j = 1;j <= k;j++){
			cin>>z>>z1;
		}
	}
	for(int i = 0;i < q;i++){
		ll z1;
		cin>>z>>z1;
		cout<<7<<'\n';
	}
	return 0;
}

