#include <bits/stdc++.h>
using namespace std;

struct node {
	long long cnt;
	char c;
} arr[200010];
queue<node> que_1;
queue<node> que_2;
long long n, ans, len_1, len_2, sum, flag_1, flag_2;
node tmp_1, tmp_2;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld %c", &arr[i].cnt, &arr[i].c);
		sum += arr[i].cnt;
	}
	sum /= 2;
	for(int i = 1; i <= n; i++) {
		int j = n - i + 1;
		if(len_1 < sum) {
			if(len_1 + arr[i].cnt <= sum) {
				que_1.push(arr[i]);
				len_1 += arr[i].cnt;
			}
			else {
				que_1.push({sum - len_1, arr[i].c});
				len_1 = sum;
			}
		}
		if(len_2 < sum) {
			if(len_2 + arr[j].cnt <= sum) {
				que_2.push(arr[j]);
				len_2 += arr[j].cnt;
			}
			else {
				que_2.push({sum - len_2, arr[j].c});
				len_2 = sum;
			}
		}
	}
	while(((!que_1.empty()) || flag_1 == 1) || ((!que_2.empty()) || flag_2 == 1)) {
		node now_1, now_2;
		if(flag_1 == 0) {
			now_1 = que_1.front();
			que_1.pop();
		}
		else {
			now_1 = tmp_1;
			flag_1 = 0;
		}
		if(flag_2 == 0) {
			now_2 = que_2.front();
			que_2.pop();
		}
		else {
			now_2 = tmp_2;
			flag_2 = 0;
		}
		long long num = min(now_1.cnt, now_2.cnt);
		if(now_1.cnt != now_2.cnt) {
			if(now_1.cnt > now_2.cnt) {
				tmp_1 = {now_1.cnt - now_2.cnt, now_1.c};
				flag_1 = 1;
			}
			else {
				tmp_2 = {now_2.cnt - now_1.cnt, now_2.c};
				flag_2 = 1;
			}
		}
		if(now_1.c != now_2.c) {
			ans += num; 
		}
	}
	printf("%lld\n", ans);
	return 0;
}
