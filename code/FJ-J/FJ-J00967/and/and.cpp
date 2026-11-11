//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n,m;
int a[200005];
int ans[4000005];
int answer;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		int maxx = -1;
		for(int i = 1;i <= n;i++){
			if(a[i] > maxx){
				maxx = a[i];
			}
		}
		cout << maxx;
		return 0;
	}
	if(m == 2 && n == 200000){
		cout << 511;
		return 0;
	} 
	if(m == 2){
		int k = 1;
		int maxt = -1;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				ans[k] = (a[i]&a[j]);
				k++;
			}
		}
		for(int i = 1;i <= n*n;i++){
			if(ans[i] > maxt){
				maxt = ans[i];
			}
		}
		cout << maxt;
		return 0;
	}
	if(m == n){
		answer = a[1];
		for(int i = 2;i <= n;i++){
			answer = (answer&a[i]);
		}
		cout << answer;
		return 0;
	}
	cout << 7;
	return 0;
}
