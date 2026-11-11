#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int m, n;
long long sum =-1;
long long a[100005];
int xx = 0;
int cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		sum = max(sum, a[i]);
		int g = a[i]+1;
		while (a > 0){
			if (g % 2 == 0) g %= 2;
			else {
				xx = 1;
				g = 0;
			}
			
		}
    }
    if (m == 1) {
    	cout << sum;
    	return 0;
    }
    if (m == 2){
    	sum = -1;
    	for (int i = 1;i <= n;i++){
    		for (int j = i+1;j <= n;i++){
    			sum = max(sum, a[i] & a[j]);
			}
		}
		cout << sum;
        return 0;
	}
	if (xx == 0){
		sort (a+1, a+n+1, cmp);
		cout << a[m];
	}
	fclose(stdin);
	fclose(stdout);
}
