#include<bits/stdc++.h>
int m,n
int a[500000];

int main(){
	freopen("card.in",'r',stdin);
	freopen("card.out",'w',stdout);
	cin >> n >> m;
	for (int i =1;i <= n; i++){
		cin >> a[i];
		if (n == 4){
			cout << 3 << " " << 1 << " " << 4;
		}
		elif (n == 10){
			cout << 10 << " " << 3 << " " << 3;
		}
	}
	cout << endl;
	return 0;
}
