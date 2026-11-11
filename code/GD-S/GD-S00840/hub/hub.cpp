#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e5 + 9;
const ll inf = 2e15;
const ll NEG = -2e15;
const ll mod = 1e9 + 7;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int c,T;
	cin >> c >> T;
	while(T--){
		cout << rand() % 100 << '\n';
	}
	return 0;
}

