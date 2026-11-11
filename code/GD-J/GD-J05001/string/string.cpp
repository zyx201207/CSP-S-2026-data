# include <bits/stdc++.h>
using namespace std;


int arr[(int)2e5];
char ch[(int)2e5];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; cin >> n;
	if (n == 1){
		cout << 0;
		return 0;
	}
	if (n == 2){
		int n1, n2;
		char c1, c2;
		cin >> n1 >> c1 >> n2 >> c2;
		cout << (long long)(c1 != c2) * min(n1, n2);
		return 0;
	}
	int i, j;
	for (i = 0; i < n; ++i){
		cin >> arr[i] >> ch[i];
	}
	if (n <= 2000 && *max_element(arr, arr + n) <= 50){
		string str;
		for (i = 0; i < n; ++i){
			for (j = 0; j < arr[i]; ++j){
				str += ch[i];
			}
		}
		int res = 0;
		for (i = 0; i < str.length() / 2; ++i){
			res += (str[i] != str[str.length() - 1 - i]);
		}
		cout << res;
		return 0;
	}
	long long res = 0;
	for (i = n - 1; i >= n / 2; --i){
		if (n % 2 && i == n / 2){
			break;
		}
		if (arr[i] == arr[n - 1 - i]){
			if (ch[i] == ch[n - 1 - i]){
				continue;
			} else {
				res += arr[i];
				ch[i] = ch[n - 1 - i];
			}
		} else {
			int last = arr[i];
			arr[i] = arr[n - 1 - i];
			arr[i - 1] -= (arr[i] - last);
			res += (long long)(ch[i] != ch[i - 1]) * abs(arr[i] - last);
			res += (long long)(ch[i] != ch[n - 1 - i]) * arr[i];
		}
	}
	cout << res;
}

