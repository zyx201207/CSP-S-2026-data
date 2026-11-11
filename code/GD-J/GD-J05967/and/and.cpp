#include <iostream>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, max, maxs;
	long long a[200005];
	string b[200005];
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	max = 0;
	maxs = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 2 ** 30; j >= 2; j/2){
			if(a[i] > j){
				b[i] += "1";
				a[i] -= j;
				max++;
			}
		}
		if(max > maxs){
			maxs = max;
		}
    }
    for(int i = 1; i <= n; i++){
    	if(b[i].size)
	}
} 
