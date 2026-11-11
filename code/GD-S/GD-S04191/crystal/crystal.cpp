#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
long long n, m, coss, ans;
bool eqq = 1;
long long a[(int)5e5 + 5], b[(int)5e5 + 5];

int main(){
	///*
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	//*/
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		eqq &= (a[i] == a[i-1]);
	}
	
	if (eqq){
		cout << n;
		exit(0);
	}
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++){
		ans = i;
		b[i] = a[i] - a[i-1];
		if (i == 1) continue;
		if (i == 2){
			coss = b[1];
		}
		else {
			coss += (b[i] * (i - 1));
		}
		// cout << "i: " << i << ", coss: " << coss << ", b[i]: " << b[i] << "\n";
		
		if (coss > m){
			ans = i; int x = a[ans]; i = 1;
			while (coss > m){
				coss -= (x - a[i]);
				ans --; i ++;
			}
			break;
		}
		if (coss == m){
			while (a[i] == a[(i+1)]){
				i += 1;
			}
			ans = i;
			break;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
