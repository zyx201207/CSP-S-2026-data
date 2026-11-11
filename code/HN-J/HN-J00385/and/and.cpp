#include <bits/stdc++.h>
using namespace std;




int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int res = 0, num, cnum, cnt = 0, temp, si = 0;
	int arr[105], raar[105];
	//vector<int> arr;

	cin >> cnum >> num;

	for (int i=0; i<cnum; i++) {
		cin >> arr[i];
		si++;
	}
    sort(&arr[0], &arr[si-1]);
    res = arr[si-1];
    for (int i=si-1; i<si-1-num; i--) {
    	res = res & arr[i];
	}
	
	cout << res;


	//cout << 12;



	return 0;
}
