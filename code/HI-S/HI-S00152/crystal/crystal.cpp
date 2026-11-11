#include<bits/stdc++.h>
using namespace std;
int n, m, a[10086],b[10086],e[10086];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (a[i] >= a[j] && i != j){
				b[i] += a[i] - a[j];
			}
			if(b[i] <= m){
				e[i]++;
			}
			else{
				cout << e[i];
				break;
			}
			if(b[i] = m){
				cout << e[i];
				break;
			}
		}
	}
	return 0;
}
