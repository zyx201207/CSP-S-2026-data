#include<bits/stdc++.h>
using namespace std;
int const N = 2e5+10;
long long n, ans = 0;
long long s[N];
string dui[N];//代表数字 
string a[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i];//几个 
		cin >> dui[i];
	}
	long long chang = 0;
	int xx=1;
	for(int i = 1; i <= n; i++){
		chang += s[i];
		for(int j = 1; j <= s[i]; j++){
			a[xx++] = dui[i];
		}
	}
	for(int i = 1; i <= chang/2; i++){
		if(a[i] != a[chang-i+1]){
			ans++;
		}
	}
	cout << ans;
	return 0; 
}

