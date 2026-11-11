#include <iostream>
#include <algorithm>
using namespace std;

long long n,m;
int a[50001];
int c[50001]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i < n;i++){
		c[i] = a[i+1] - a[i];
	}
	int arr[101]={0};
	for (int i = 1;i < n;i++){
		arr[i] = arr[i-1] + c[i];
		//cout << arr[i] << " " << c[i] << endl;
	}
	long long ans = 0;
	long long i = 1;
	while (ans <= m && i <= n){
		ans += arr[i];
		i++;

	}
	cout << i-1;
	return 0;
} 
