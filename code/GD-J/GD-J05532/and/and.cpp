#include <bits/stdc++.h>
using namespace std;
int ad,n,m,k;
void diaoyong(int a){
	if (a = m){
		ad &= a;
		if (ad > k){
			k = ad;
		}
		return;
	}
	for (int i = a + 1;i <= n;i++){
		ad &= i;
		diaoyong(i);
	} 
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int a[20005];
	for (int i = 1;i <= n;i++){
		int l;
		cin >> l;
		a[i] = l;
	}
	k = -1;
	for (int i = 1;i <= n;i++){
		ad = i;
		diaoyong(i);
	}
	cout << k;
	return 0;
}
