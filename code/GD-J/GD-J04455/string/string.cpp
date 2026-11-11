#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
long long cnt;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
		b[i] = a[i];
		a[i] += a[i-1];
		cin >> c[i];
	}
	for (int i = n;i >= 1;i --){
		b[i] += b[i+1];
	}
	long long pl1 = 0,pl2 = 0,pr1 = n,pr2 = 0;
	while (pl1+1 < pr1){
		pl1 ++;
		pl2 = a[pl1];
		while (pr2 < pl2){
			if (b[pr1] > pl2){
				if (c[pr1] != c[pl1])cnt += pl2 - pr2;
				pr2 = pl2;
				break;
			}
			else{
				if (c[pr1] != c[pl1])cnt += b[pr1] - pr2;
				pr2 = b[pr1];
				pr1 --;
			}
		}
	} 
	cout << cnt;
	return 0;
}
