#include <bits/stdc++.h>
using namespace std;
long long s[200005], z[200005], num[200005];
long long a[200005];
int main(){
	freopen("card.in", "r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int j;
	for(int i = 1; i <= n; i++){
		cin >> z[i];
		
	}
	for(int i = 1; i <= n; i++){
		j = 1;
		for(int b = i; b <= n; b++){
			j++;
			if(s[z[b]] == 1){
				for(int o = j; o >= 0; o--){
					a[j] = 0;
					j -= 1;
					if(a[j] == z[b]) break;
				}
			}
			a[j] = z[b];
			s[z[b]] = 1;
		}
		for(int l = 0; l <= j; l++){
			num[a[l]]++;
			a[l] == 0;
		}
		for(int l = 0; l <= n; l++){
			s[l] == 0;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << num[i] << " ";
	}
	return 0;
}
