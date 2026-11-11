#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("card4.in", "r", stdin);
	//freopen("card4.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	stack <int> c;
	int n, m, a[500005], b[300005] = {}, d[300005] = {}, s = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int flag = 0;
			for(int k = 1; k < j; k++){
				if(d[k] == a[j]){
					flag = k;
					break;
				}
			}
			if(flag >= 1){
				for(int k = flag; k < j; k++){
					c.pop();
					d[s--] = 0;
				}
				c.push(a[j]);
				d[++s] = a[j];
				for(int k = 1; k <= s; )
				break;
			}
			c.push(a[j]);
			d[++s] = a[j];
		}
	}
	for(int i = 1; i <= m; i++){
		cout << b[i] << " ";
	}
	
	return 0;
}
