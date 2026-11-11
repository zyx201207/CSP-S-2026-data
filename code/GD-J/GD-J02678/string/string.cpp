#include <bits/stdc++.h>
using namespace std;

struct str{
	long long l;
	char c;
};

int main(){
	//freopen("string6.in", "r", stdin);
	//freopen("string6.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	str a[200005];
	int n;
	long long result = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].l >> a[i].c;	
	}
	int i = 1, j = n;
	while(i < j){
		int sinn = min(a[i].l, a[j].l);
		if(a[i].c != a[j].c){
			result += sinn;
		}
		a[i].l -= sinn;
		a[j].l -= sinn;
		if(a[i].l == 0) i++;
		if(a[j].l == 0) j--;
	}
	cout << result;
	
	return 0;
}
