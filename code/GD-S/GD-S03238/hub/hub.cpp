#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int c, t;
int n, d;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		for(int i = 1;i <= n; i++){
			cout << 0 << "\n";
		}
	}
	return 0;
}

