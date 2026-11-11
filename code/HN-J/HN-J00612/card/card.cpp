#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005] , p = 1;
long long tab[500005];
long long ap[300005];
int main( ){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) scanf("%d" , &a[i]);
	for(int j = 1;j <= n;j ++){
		p = 1;
		for(int i = j;i <= n;i ++){
			if(i != j){
				for(int k = 1;k < p;k ++){
					if(tab[k] == a[i]){
						p = k;
						break;
					}
				}
			}
			tab[p] = a[i];
			p ++;
		}
		//tab[p] = a[n];
		//cout << a[n] << " ";
		//cout << j << ": ";
		//print();
		for(int i = 1;i < p;i ++){
			ap[tab[i]] ++;
		}
		memset(tab , 0 , p * 4);
	}
	for(int i = 1;i <= m;i ++){
		printf("%lld " , &ap[i]);
	}
	return 0;
}
