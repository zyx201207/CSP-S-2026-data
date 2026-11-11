#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[int(2e5)+5];
    cin >> n;
	char c[int(2e5)+5];
	long long sumlen = 0;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i] >> c[i];
	}
	int posi = 1, posj = a[n], blki = 1, blkj = n;
	long long ans = 0;
	while(blki <= n && blkj >= 1) {
		if(c[blki] != c[blkj]) {
			ans += min(a[blki] - posi + 1, posj);
		} 
		if (a[blki] - posi > posj - 1) {
			posi += posj;
			blkj --;
			posj = a[blkj];
		} else if (a[blki] - posi < posj - 1){
			posj -= a[blki] - posi + 1;
			blki ++;
			posi = 1;
		} else {
			blki ++;
			blkj --;
			posi = 1;
			posj = a[blkj];
		}
		if (blki >= blkj) break;
	}
	cout << ans;
	return 0;
}
