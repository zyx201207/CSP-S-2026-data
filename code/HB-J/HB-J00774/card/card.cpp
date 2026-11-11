#include <bits/stdc++.h>
using namespace std;

// n^2 sihu haoxiang youdian butaixing a
// dagai yinggai huoxu keneng yisi haoxiang  neng hundao ba

void push(int a[], int val, int& top) {
	while(a[top-1] != val) {
		--top;
	}
	a[top++] = val;
}

int alive_cnt[500005];
int all_cards[500005];
int visited[500005];
	int cards[500005];

void simulate(int n, int a[], int nth_game) {
	int put[500005] = {0}; 
	memset(put, 0, n);
	int top = 0;
	for (int i = nth_game; i < n; i++) {
		if (!put[cards[i]]) {
			a[top++] = cards[i];
			put[cards[i]] = true;
			continue;
		}
		push(a, cards[i], top);
		cout << "k:" << cards[i] << '/' << i << endl;
		cout << "a:";
	for (int j = 0; j < top; j++)
 {
	    cout << a[j] << '/' << put[a[j]] << ' ';
	}
	}
		cout << endl;for (int i = 0; i < top; i++) {
		alive_cnt[a[i]]++;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	for (int i = 0; i < n; i++) {
		int a[500005];
		memcpy(a, cards, n);
		simulate(n, a, i);
	}
	sort(cards, cards + n, greater<>());
	for (int i = 0; i < n; i++) {
		while(cards[i] == cards[i+1] && i + 1 < n) i++;
		cout << alive_cnt[cards[i]] << '/' << i << ' ';
	}
	cout << endl;
	return 0;
}
