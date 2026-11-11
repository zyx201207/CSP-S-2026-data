//GZ-J00410 肖耿毅 兴义市弘毅中学
//结束了。。。
//Away From OI 
#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500050];
long long point[300050];
long long ans[300050];
struct stk {
	long long mem[500050];
	long long head = 0;
	void push(long long x) {
		mem[++head] = x;
	}
	void pop() {
		head--;
	}
	long long top() {
		return mem[head];
	}
	long long size() {
		return head;
	}
} q;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) {
		//puts("here!");
		for(int j = 1; j <= m; j++) point[j] = 0;
		for(int j = i; j <= n; j++)
			if(point[a[j]] == 0) {
				q.push(a[j]);
				point[a[j]] = q.size();
			} else
				for(int k = q.size(); k > point[a[j]]; k--) {
					point[q.top()] = 0;
					q.pop();
				}
		for(int j = q.size(); j > 0; j--) {
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i = 1; i <= m; i++)
		printf("%lld ", ans[i]);
	puts("");
	return 0;
}
