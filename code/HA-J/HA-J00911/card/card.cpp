#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin >> a >> b;
	int c[500008];
	int d[500008];
	for(int i = 1;i <= a;i++){
		cin >> c[i]; 
	}
	int e[500008];
	for(int i = 1;i <= a;i++){
		memset(e,0,sizeof(c));
		for(int j = i;j <= a;j++){
			e[j] = c[j];
			for(int m = 1;m < j;m++){
				if(e[j] == e[m]){
					int f = m;
					for(int n = 1;n <= m;n++){
						e[n] = 0;
					}
				}
			}
		}
		for(int k = 1;k <= a;k++){
			int t = d[k];
			d[t] += 1;
		}
	}
	for(int i = 1;i <= b - 1;i++){
		cout << e[i] << " ";
	}
	cout << e[b];
	return 0;
}
