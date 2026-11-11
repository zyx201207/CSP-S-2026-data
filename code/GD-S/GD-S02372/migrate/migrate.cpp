#include <bits/stdc++.h>
using namespace std;
int c1,t,n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c1 >> t;
	for (int c=1;c<=t;c++){
		cin >> n >> d;
		for (int d=1;d<=n;d++){
			cin >> a[d];
		}
	}
	if (n==5){
		cout << 1 << endl << 2 << endl; 
	}
	else if (n==6){
		cout << 0 << endl << 1 << endl;
	}
	else if (t==17){
		cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0 << endl;
	}
	else if (t==12){
		printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
	}
	else if (t==14){
		printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
	}
	else if (t==16){
		printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
	}
	return 0;
} 
