#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long sl,zl,z[100005];
	cin >> sl >> zl;
	for (long long i = 0;i < sl;i++){
		cin >> z[i];
	}
	for (long long i = 1;i < sl;i++){
		cout << i << " ";
	}
	return 0;
}

