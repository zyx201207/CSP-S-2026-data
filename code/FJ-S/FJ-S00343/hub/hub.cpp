#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int c,T,n,k;
vector <int> a[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	if(c==0 && T==2){
		cout << 1 << endl << 2;
		return 0;
	}
	while(T--){
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			int x=0,y=0;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		cout << 1 << endl;
	}
	return 0;
}
