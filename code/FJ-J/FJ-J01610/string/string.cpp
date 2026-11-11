#include <bits/stdc++.h>
using namespace std;
int a[15],b[15];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	} 
	for(int i =1;i <= n;i++){
		int x;
		char ch;
		cin >> x >> ch;
		a[i] = x;
		b[i] = ch;
	}
	for(int i = 1;i <= n;i++){
		if (a[i] < a[i+1] || a[i] < a[i - 1]){
			cout << a[i];
			return 0;
		} else if(a[i] > a[i+1] ){
			cout << a[i + 1];
			return 0;
		}else if(a[i] > a[i - 1]){
			cout << a[i -1];
			return 0;
		}else if(a[i] == a[i - 1] || a[i] == a[i + 1]){
			cout << 0;
			return 0;
		}
	}
	return 0;
}

