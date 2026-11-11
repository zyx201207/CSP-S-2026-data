#include <bits/stdc++.h>
using namespace std;
#define elif else if
int n, a[200005];
long long ans = 0;
char c[200005];
bool allsame(int mx){
	for (int i = 1, j = mx; i < j;){
		if (c[i] != c[j]) return 0;
		i++;
		j--;
	}
	return 1;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	// CCF has no eggs!
	int l = 1, r = n;
	if (allsame(n)){
	    cout << 0;
		return 0; 
	}
	while (l < r){
		if (a[l] != a[r] && c[l] == c[r]) ans += abs(a[l] - a[r]); 
		elif (a[l] == a[r] && c[l] != c[r]) ans += a[l];
		elif (a[l] != a[r] && c[l] != c[r]) ans += max(a[l], a[r]); 
		l++;
		r--;
	}
    cout << ans; 
	return 0;
}
// but how can I do?
// there's too much things to do!!!!!!!!!
// I CAN'T TAKE IT ANYMORE!!!!!!!!!!!!!!!!!!!!!!!!1
// 6767789178666767676767676767676767676767676767676767676767676767676767
// let me have a sleep...
// zzzzzzzzzzzzzzzzzzzzzz
// ne atashi shitteru yo~()() CCF! You can't escape!
// hatsune miku is a god who lives FOREVER!!!
// zui4 hou4 wo3 hai2 shi4 zhu4 yyh, ytj, ycx, wyt, sxr deng3 ren2 RP++.
// I will kill CJY, bjSMC, YZM, OYZ
//写完感觉好通透啊 
//

/*
juujou nani sore? aijou nani sore?
oshii mon de oshii mon dena!
ranbou dame dame! ganjou sutesare!
isseirito shinunde otore!
*/

/*
aa
ba
a
*/
