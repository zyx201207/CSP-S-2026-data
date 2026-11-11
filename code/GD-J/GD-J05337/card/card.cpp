#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[300005], c[300005], t;
stack<int>z;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int t = 1; t <= n; t++){
		for(int i = 0+t; i <= n; i++){
			int x = a[i];
			z.push(x);
			b[x]++;
			if(b[x] > 1){
				b[x]--;
				z.pop();
				while(z.top() != x){
					b[z.top()]--;
					z.pop();
				}
			}
		}
		
		while(!z.empty()){
			c[z.top()]++;
			z.pop();
		}
	}
	
	for(int i = 1; i <= m; i++)
		cout << c[i] << " ";
	
	return 0;
}
