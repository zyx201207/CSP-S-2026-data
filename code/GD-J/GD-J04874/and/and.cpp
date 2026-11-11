#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,arr[200105],x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> arr[i];
	sort(arr + 1,arr + 1 + n,greater<int>());
	x = arr[1];
	for(int i = 2;i <= m;i++){
		x = x & arr[i];
	}
	cout << x;
	return 0;
}
