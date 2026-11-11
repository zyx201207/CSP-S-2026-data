#include <bits/stdc++.h>
using namespace std;

int n, m, top = 0;
int a[200001], a1[200001], nu[200001] = {0};

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	bool flag = true;
	for(int i = 1; i <= n; i++){
		top = 0;
		a1[++top] = a[i];
		for(int j = i + 1; j <= n; j++){
			flag = true;
			for(int k = 1; k <= top; k++){
				if(a[j] == a1[k]){
					top = k;
					flag = false;
				}
			}
			if(flag){
				a1[++top] = a[j];
			}
		}
		for(int j = 1; j <= top; j++){	
			if(a1[j] <= m){
				nu[a1[j]]++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		printf("%d ", nu[i]);
	}
	return 0;
} 
