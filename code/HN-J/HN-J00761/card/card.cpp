#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500050], b[500050], B[300050];
int main(){
	//Trick||Treat!
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}for(int i = 1;i <= n;i++){
		bool f = 0;
		for(int k = i;k <= n;k++){
			if(b[a[k]] == 0){
				b[a[k]] = k;
			}else if(b[a[k]] != 0){
				for(int j = b[a[k]];j < k;j++){
					b[a[j]] = 0;
				}
				b[a[k]] = k;
			}
		}for(int j = 1;j <= m;j++){
			if(b[j] != 0){
				B[j]++;
			}
			b[j] = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << B[i] << ' ';
	}
	return 0;
} 
