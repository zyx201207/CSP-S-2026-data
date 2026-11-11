#include <bits/stdc++.h>
using namespace std;
int a[100005], n, sum[100005], m;
int que[100005], t=1, e=1;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	for (int i = 1;i <= n;i++){
		for (int h = 1;h <= n;h++){
			que[h]=0;
		}
	    t=1;
	    e=1;
		for (int j = i;j <= n;j++){
			int l = -1;
			for (int k = t;k <= e;k++){
				if (a[i] == que[k]){
					l = i;
				}
			}
			if (l == -1){
				que[e] = a[i];
				e++;
			}
			else{
				t = l;
				que[e] = a[i];
				e++; 
			}
		}
		for (int d = t;d <= e;d++){
			sum[que[d]]++;
	    }
	}
	for (int i = 1;i <= m;i++){
		cout << sum[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
}
