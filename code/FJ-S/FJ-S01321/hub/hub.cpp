#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e5 + 5;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	ll t;
	srand(time(0));
	cin >> t;
	while(t--)cout << rand() % 3 << "\n";
	return 0;
}
// warning:"==",全局变量,freopen,check_code


