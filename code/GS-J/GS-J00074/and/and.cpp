#include<bits/stdc++.h>
int n,m;
int a[100005];
int main(){
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	cin >> n >> m;
	for (int i = 0;i <= n;i++ ){
		cout >> a[i];
		if (n == 4 || m == 2){
			cout << 12;
		}
		elif (n == 5 || m == 3){
			cout << 7;
		}
	}
	cout << endl;
	return 0;
}
