#include<bits/stdc++.h>
using namespace std;
using t64 = long long;
t64 c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c>>t;
	srand(time(0));
	while(t--){
		cout << rand() << '\n';
		srand(rand());
	}
	return 0;
} 
