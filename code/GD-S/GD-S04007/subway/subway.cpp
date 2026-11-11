#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
int c,n,m,d,q,st,ed;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	bool f=1;
	for(int i=1;i<=n;i++){
		int k;cin >> k;
		for(int j=1;j<=k;j++){
			int ac,wa;
			cin >> ac >> wa;
		}
	}
	while(q--){
		cin >> st >> ed;
		cout << w[st]+w[ed]+152719;
	}
}
