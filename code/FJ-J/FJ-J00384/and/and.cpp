#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and1.in","r",stdin);
	freopen("and1.ans","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[115414],b[1001],c[10086];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j <= a[i];j++){
			b[j] = a[i]%2;
		}
	}for(int i = 0; i < n; i++){
		for(int j = 0; j <= a[i];j++){
			b[j] = a[i]%2;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = a[i]; j >= 0;j--){
			c[i] = b[j];
		}
	}
	if(m == 1){
		int max = a[0];
		for(int i = 1; i < n; i++){
			if(max < a[i]){
				max = a[i];
			}
			cout << max;
		}
	}else if(m == n){
		int total = c[0];
		for(int i = 1; i < n; i++){
			total = total & c[i];
		}
		cout << total;
	}else if(m == 2){
		int max = c[0]&c[1];
		for(int j = 1; j < n; j++){
			if(c[j]&c[j+1] > max){
				max = c[j]&c[j+1];
			}
		}
	}else{
		int max = c[0]&c[1]&c[2];
		for(int j = 2; j < n; j++){
			for(int k = 3; k <= n;k++){
				if(c[j]&c[k]&c[k+1] > max){
				max = c[j]&c[k]&c[k+1];
				}
			}	
		}
		cout << max;
	}
	return 0;
}
