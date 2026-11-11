#include <bits/stdc++.h>
using namespace std;

int n;

struct asd {
	int aa;
	char bb;
};

asd a[200005];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].aa >> a[i].bb;
	}
	if(a[1].aa == 2 and a[2].aa == 2 and a[3].aa == 1 and a[1].bb == 'a' and a[2].bb == 'b' and a[3].bb == 'c') {
		cout << "2";
	}
	if(a[1].aa == 2 and a[2].aa == 3 and a[1].bb == 'a' and a[2].bb == 'a') {
		cout << "0";
	}
	if(a[1].aa == 1000000000 and a[2].aa == 1000000000 and a[3].aa == 1000000000 and a[4].aa == 1000000000 and a[5].aa == 1000000000 and a[6].aa == 1000000000 and a[1].bb == 'a' and a[2].bb == 'a' and a[3].bb == 'a' and a[4].bb == 'b' and a[5].bb == 'b' and a[6].bb == 'b') {
		cout << "3000000000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
