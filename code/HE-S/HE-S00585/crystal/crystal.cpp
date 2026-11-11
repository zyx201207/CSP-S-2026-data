#include <bits/stdc++.h>
using namespace std;

long n,m,sum;
long a[100001];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			a[i] += j;
			a[i + j] += m-j;
			for (int k = 1;k <= j;k++){
				if(a[i] == a[i + k]){
					sum++;
				}
			}
		}
	}
	cout << sum;
	return 0;
} 
