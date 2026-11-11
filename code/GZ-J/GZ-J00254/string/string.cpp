//GZ-J00254 遵义市新蒲新区白鹭湖小学 韩定远
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node{
	long long num;
	char c;
}a[N];
string s;
long long len, l, r, cnt, n, num;
char c;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	if (n == 1){
		cout << 0;
		return 0;
	}
	if (n <= 2000){
		for (long long i = 1; i <= n; i++){
			scanf("%lld", &num);
			cin >> c;
			for (long long j = 1; j <= num; j++){
				s += c;
			}
		}
		len = s.size();
		l = 0, r = len - 1;
		while (l <= r){
			if (s[l] != s[r]) cnt++;
			l++;
			r--;
		}
		printf("%lld", cnt);
		return 0;
	} else {
		for (long long i = 1; i <= n; i++){
			scanf("%lld", &a[i].num);
			cin >> a[i].c;
		}
		len = n;
		l = 0, r = len - 1;
		while (l <= r){
			if (a[l].c != a[r].c) cnt += a[l].num;
			l++;
			r--;
		}
		printf("%lld", cnt);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
}
