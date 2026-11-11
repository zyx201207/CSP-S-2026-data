#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>> n >> m;
	int cnt = 0;
	int x = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] > x){
			x = a[i];
		}
		cnt = cnt and a[i];
	}
	if(m == n){
		cout << cnt;
		return 0;
	}
	int max = 0;
	if(m == 2){
		for(int i = 1;i <= n - 1;i++){
			for(int j = i + 1;j <= n;j++){
				if(a[i] and a[j] > max){
					max = a[i] and a[j];
				}
			}
		}
		cout << max;
		return 0;
	}
	if(m == 1){
		cout << x;
		return 0;
	}
	if(m == 3){
	    max = 0;
    	for(int i = 1;i <= n - 2;i++){
	    	for(int j = i + 1;j <= n - 1;j++){
			    for(int k = j + 1;k <= n;k++){
				    if(a[i] and a[j] and a[k] > max){
					    max = a[i] and a[j] and a[k];
			    	}
			    }
		    }
	    }
    }
	cout << max;
	return 0;
}
