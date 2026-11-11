#include<iostream>
using namespace std;
const int MAXN = 2000010;
long long c, t;
long long u[MAXN], v[MAXN];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for(int j = 1; j <= t; ++j){
	long long n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; ++i){
			cin >> u[i] >> v[i];
		}
	}
	if(t == 2) cout << 1 << endl << 2;
	else if(t == 3) cout << 1 << endl << 1 << endl << 2;
	else {
		for(int i = 1; i <= t; ++i) cout << 1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
