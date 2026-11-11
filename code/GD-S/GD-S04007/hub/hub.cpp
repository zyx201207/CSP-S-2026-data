#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>e[20];
mt19937_64 rnd(time(0));
int get(){
	return rnd()%1000000000;
} 
void solve(){
	cout << get() << "\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin >> c >> t;
	while(t--)solve();
}
