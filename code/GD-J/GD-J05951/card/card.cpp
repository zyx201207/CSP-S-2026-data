#include<bits/stdc++.h>
using namespace std;
struct Node{
	int num, d;
}a[500010];
int x[300010];
int s[500010];
bool f[300010];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i].num;
		a[i].d = i;
	}
	for (int i = 1; i < n; i ++){
		for (int j = i+1; j <= n; j ++){
			if (a[j].num == a[i].num && !f[a[i].num]){
				int v = a[i].d;
				a[i].d = a[j].d;
				a[j].d = v; 
				f[a[i].num] = true;
			}
		}
	}
	for (int t = 1; t <= n; t ++){
		for (int i = 1; i <= 300010; i ++){
			x[i] = 0;
		}
		for (int i = t, c = (i%n == 0 ? n : i%n); i <= n+t-1; i ++){
			x[a[c].num] ++;
			if (x[a[c].num]>1){
				for (int k = a[c].d; k <= n; k ++){
					x[a[k].num] --;
				}
			}
		}
		for (int i = 1; i <= m; i ++){
			if(x[i]>0){
				s[i] ++;
			}
		}
	}
	for (int i = 1, j = 0; i <= m; i ++){
		if (s[i]>0){
			if (j == 1) cout << " ";
			cout << s[i];
			j = 1;
		}
	}
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
