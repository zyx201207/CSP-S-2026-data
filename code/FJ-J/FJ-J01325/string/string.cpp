#include<bits/stdc++.h>
using namespace std;
struct stu{	
	long long a;
	char b;
};
stu s[200005];
long long n, cnt, k = 1, sum;
string result;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i ++){
		cin >> s[i].a >> s[i].b;
		cnt += s[i].a;
		for(; k <= cnt; k ++){
			result[k] = s[i].b; 
		}
	}
	if(cnt % 2 == 1) {
		for(int i = cnt / 2 + 2; i <= cnt; i ++){
			result [i - 1] = result[i];
		}
		cnt--;
	}
	for(int i = 1, j = cnt; i <= cnt / 2, j > cnt / 2; i ++, j--){
		if(result[i] != result[j])
			sum ++;
	}
	cout << sum;
	return 0;
}
