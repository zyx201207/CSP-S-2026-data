#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500005],b[500005],c = 0,k = 0;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(a[j] <= a[i]){
				b[k] = a[i]-=a[j];
				k++;
			}
		}
	}
	int i = k-1;
	while(c <= m && i >= 0){
		c += b[i];
		b[i] == 0;
		i--;
	}
	cout << c;
	freclose(stdin);
	freclose(stdout);
	return 0;
}
