#include <bits/stdc++.h>
using namespace std;

int n,m,a[2000005],box[10000005];
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n >>m;
	for (int i=1 ; i<=n ; i++){
		cin >>a[i];
		box[a[i]]++;
	}
	for (int i=0 ; i<=10000005 ; i++){
		if (box[i]==m) {
			cout <<i;
			return 0;
		}
	}
	cout <<a[n];
	return 0;
}
