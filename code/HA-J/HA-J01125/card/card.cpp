#include <bits/stdc++.h>
using namespace std;
struct node{
	int val;
	bool flag;
}a[10000100];
int b[1000010];
bool c[1000100];
int counter[1000010];
void del(int x, int y){
	for (int i = x; i <= y; i++){
		b[i] = 0;
	}
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i].val;
	}
	int pos = 1;
	for (int k = 1; k <= n; k++){
		for (int i = k; i <= n; i++){
			b[pos] = a[i].val;
			if (c[a[i].val] == true){
				for (int j = k; j < i; j++){
					if (a[j].val == a[i].val){
						del(j+1, i);
						pos = j;
					}
				}
			}else c[a[i].val] = true;
			pos++;
		}
		for (int i = 1; i <= m; i++) c[i] = false;
		for (int i = 1; i <= pos; i++){
			if (c[b[i]] == false){
				counter[b[i]]++;
				c[b[i]] = true;
			}
		}
		for (int i = 1; i <= pos; i++) b[i] = 0;
		for (int i = 1; i <= m; i++) c[i] = false;
		pos = 1;
	}
	for (int i = 1; i <= m; i++){
		cout << counter[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
