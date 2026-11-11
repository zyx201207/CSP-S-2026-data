#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
ll c,n,m,d,p;
int w[N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=m; i++) {
		cout<<w[i];
	}
	return 0;
}
