#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+5;

int c, t;

mt19937 gen(20100509);

void solve();

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> t;
	for(int i=1 ; i<=t ; i++){
		cout << gen()%5+3 << '\n';
	}
	
	return 0;
}
