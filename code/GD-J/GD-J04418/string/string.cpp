#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n,x = 0,c = 0;
	char a[999999],b;
	cin >> n;
	for (int i = 0;i < n;i++){
		int z;
		cin >> z >> b;
		c += z;
		for (int j = 0;j < z;j++){
			a[x] = b;
			x++;
		}
	}
	int z = 0;
	for (int i = 0,j = c - 1;j - 1 >= i;i++,j--){
		if (a[i] - 'a' != a[j] - 'a'){
			z++;
		}
	}
	cout << z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
