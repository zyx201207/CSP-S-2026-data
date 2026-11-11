#include<bits/stdc++.h>
using namespace std;
stack<int> seat;
int n,m,A[1000006],f[1000006],cnt[1000006];
void fun(int x) {


	for(int i = x; i < n; i++) {
		cnt[A[i]]++;//放入并计数
		if(cnt[A[i]] > 1) {
			cnt[A[i]]--;

			while(seat.top() != A[i] && !seat.empty()) {
				cnt[seat.top()]--;
				seat.pop();
			}
			seat.pop();
		}
		seat.push(A[i]);
//		for(int j = 1; j <= m; j++) {
//			cout  <<cnt[j] << ' ';
//		}
//		cout << endl;
	}
//	cout << endl;
	for(int j = 1; j <= m; j++) {
		if(cnt[j] == 1) f[j]++;
	}
//	cout << endl;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for(int i = 0; i < n; i++) {
		fill(cnt,cnt+m+1,0);
		while(!seat.empty())
			seat.pop();
		fun(i);
	}
	for(int i = 1; i <= m; i++) {
		cout << f[i] << ' ';
	}
	return 0;
}
/*

*/

