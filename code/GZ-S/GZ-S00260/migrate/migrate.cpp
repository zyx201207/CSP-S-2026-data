//甘森億 GZ-S00260 贵阳市云岩区中天中学 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int c, T;
int n, m, a[N];

int main(){
///	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> m;
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			if(a[i] + m + m-1 == a[i+3]) cnt++;
		}
		cout << cnt;
	}
	return 0;
}
