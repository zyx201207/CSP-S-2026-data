#include<bits/stdc++.h>
using namespace std;
int c[300000],n7891[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m,a[500000],b[300000],q;
	bool man = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;i++){
			n7891[j] = 0;
		}
		for(int j = i;j < n;j++){
			man = 0;
			for(int k = 0;k < n;k++){
				if(a[j] == n7891[k]){
					q = k;
					man = 1;
					break;
				}
			}
			if(man){
				for(int k = q;k < n;k++){
					n7891[k] = 0;
				}
			}
			n7891[j] = a[j];
		}
		for(int j = 1;j < n;j++){
			b[n7891[j]]++;
		}
	}
	for(int i = 1;i < m;i++){
		if(i != 1){
			cout << ' ';
		}
		cout << b[i];
	}
	return 0;
} 
