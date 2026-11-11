#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdout);
	freopen("and.out","w",stdin);
	int n,m;
	cin >> n >> m;
	double a[n] = {0};
	double b[n] = {0};
	double c[n] = {0};
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	for (int i = 0;i < n;i++){
		for (int j = 0;j <= 20;j++){
			if ((a[j]/(2**j)) < 1){
				b[i] = j;
			}
		}
	}
	int max_b,count;
	max = 0;
	count = 0;
	for (int i = 0;i < n;i++){
		if (b[i]>max_b){
			max_b = b[i];
			count = 1;
		}
		else if (b[i] == max_b){
			count++;
		}
	}
	return 0;
}
