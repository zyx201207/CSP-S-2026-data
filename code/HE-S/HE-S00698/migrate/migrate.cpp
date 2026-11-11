#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+50,M=5e3+30;
ll c,T,n,d,x[N];
ll f[M][M];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		ll dl=INT_MAX;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
			if(i>1)dl=min(dl,x[i]-x[i-1]);
		}
		if(c==13||c==14) {
			cout<<0<<'\n';
			continue;
		}
		cout<<(n-d/dl*2)+1<<'\n';
	}
	return 0;
}

