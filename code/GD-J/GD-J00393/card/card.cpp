#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m;
int a[N], desk[N], num[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++){
		int cnt = 0;
		for(int j = i;j <= n;j++){
			bool f = 0;
			for(int k = 1;k <= cnt;k++){
				if(desk[k] == a[j]){
					f = 1;
					desk[cnt] = a[j];
					for(int l = cnt - 1;l >= k;l--){
						desk[l] = desk[l + 1];
						desk[l + 1] = 0;
					}
					cnt = k;
				}
			}
			if(!f) desk[++cnt] = a[j];
		}
		for(int j = 1;j <= cnt;j++){
			num[desk[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		printf("%d ", num[i]);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
