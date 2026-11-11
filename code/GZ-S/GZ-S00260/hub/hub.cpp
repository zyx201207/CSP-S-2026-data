//甘森億 GZ-S00260 贵阳市云岩区中天中学 
#include<bits/stdc++.h>
using namespace std;

int c, T;
int x, y, n, k, g=0;

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		cin >> x >> y;
		int vis;
		for(int i = 1; i <= x-1; i++){
			cin >> n >> k;
			if(g < n) g = n;
		}
		cout << x-g;
	}
	return 0;
}
