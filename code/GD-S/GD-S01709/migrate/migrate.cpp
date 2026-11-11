#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6;
ll n,d,x[N];
//±¸×¢£ºÃ»Ð´ 
void solve(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++) cin >> x[i];
	cout << n - d << endl;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t = 1,c;
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
