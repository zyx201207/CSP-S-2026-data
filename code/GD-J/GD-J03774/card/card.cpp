#include<bits/stdc++.h>
using namespace std;
int n , m , a[500010] , c[300010] , b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool bb = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(i != 1 && a[i] < a[i-1]) bb = 0;
	}
	if(bb){
		for(int i = 1; i <= n; i++){
			b[a[i]] = i;
		}
		for(int i = 1; i <= m; i++){
			printf("%d ", b[i]);
		}
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			for(int l = j+1; l <= n; l++){
				if(a[l] == a[j]){
					j = l;
				}
			}b[a[j]]++;
		}
	}for(int i = 1; i <= m; i++){
		printf("%d ", b[i]);
	}
	return 0;
}
