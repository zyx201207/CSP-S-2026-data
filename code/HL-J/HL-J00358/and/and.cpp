#include <iostream>
#include <cmath>
using namespace std;
int time;
int t;
int a[200000];
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	int max_ = 0;
	cin >> t;
	cin >> time;
	for (int i = 0 ; i < t ; i ++){
		cin >> a[i];
	}
	for (int i = 0 ; i < t ; i ++){
		max_ = max(max_ , a[i]);
	}
	cout << max_;
}
