#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[300005],sum[300005];
int main(){
	freopen(card.in,'r',stdin);
	freopen(card.out,'w',stdout);
	int n,m;cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int n1 = n;
	while (n1--){
		int n2 = n;
		for (int i = n-n1+1;i <= n2;i++){
			b[i] = a[i];
			c[a[i]]++;
			if (c[a[i]] == 2) {
				for (int j = i-1;j >= 1;j--){
					if (b[j] != b[i]) {
						b[j] = 0;
					}else {
						b[i] = 0;
						i = j;
						n2 = n2-(i-j)-1;
						break;
					}
				}
			}
		}
		for (int i = n-n1+1;i <= n2;i++){
			sum[b[i]]++;
		}
	}
	for (int i = 1;i < m;i++){
		cout << sum[i] << ' ';
	}cout << sum[m] << endl;
	return 0;
} 
