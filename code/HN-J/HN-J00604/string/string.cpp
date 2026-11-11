#include<iostream>
using namespace std;
int n;
long int r = 0;
string c;
int main(){
	cin >> n;
	long int mid;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i] >> c[i];
		mid += a[i];
	}
	if(mid % 2 == 1){
		mid = mid / 2 + 1;
	}else{
		mid = mid / 2;
	}
	string c1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < a[i]; j++){
			c1 += c[i];
		}
	}
	if(mid % 2 == 1){
		for(int i = 0; i < mid - 1; i++){
			if(c1[i] != c1[(mid - 1) * 2 - i - 1]){
				r += 1;
			}
		}
	}else if(mid % 2 == 0){
		for(int i = 0; i < mid; i++){
			if(c1[i] != c1[mid * 2 - i - 1]){
				r += 1;
			}
		}
	}
	cout << r;
	return 0;
}
