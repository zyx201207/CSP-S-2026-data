#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int N = 2e5+10;
priority_queue<int> q;
int sum[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		int a;
		cin >> a;
		q.push(a);
	}
	int mxans = q.top();
	for (int i = 1;i <= m;i++){
		mxans &= q.top();
		q.pop();
	}
	cout << mxans;
	return 0;
}
