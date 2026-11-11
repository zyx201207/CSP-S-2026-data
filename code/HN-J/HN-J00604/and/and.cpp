#include<iostream>
using namespace std;
int n, m;
int f(int i, int list[], int a[]){
	if(i == m){
		int r = list[0] & list[1];
		for(int j = 2; j < m; j++){
			r = r & list[j];
		}
		return r;
	}else{
		list[i] = a[i];
		int r = f(i + 1, list, a);
		for(int j = i + 1; j < n; j++){
			list[i] = a[j];
			if(f(i + 1, list, a) > r){
				r = f(i + 1, list, a);
			}
		}
		return r;
	}
}
int main(){
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int x[m];
	cout << endl << f(0, x, a) << endl;
	return 0;
}
