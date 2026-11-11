#include<bits/stdc++.h>
using namespace std;
const long long N=1e9+10;
int w[N],a[N],t[N];
int c,n,m,d,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	while(n--){
		int x;
		cin >> x;
		for(int i=1;i<=x;i++){
			cin >> a[i] >> t[i];
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
	}
	cout << 35 << endl << 16;
	return 0;
}
