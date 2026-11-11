//甘森億 GZ-S00260 贵阳市云岩区中天中学 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5*5+10;
long long n, m, a[N], cnt = 1, g = 0;
int minn = INT_MAX;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] < minn){
			 minn = a[i];
			 g = i;
		}
	}
	for(int i = 1; i <= n; i++){
		int x = a[g+i]-a[g];
		if(m >= x*i){
			cnt++;
			int y = i;
			for(int j = y; j >= 0; j--){
				a[g+j] += x;
			}
			m -= x*i;
		}
		else break;
    }
    cout << cnt;
	return 0;
}
