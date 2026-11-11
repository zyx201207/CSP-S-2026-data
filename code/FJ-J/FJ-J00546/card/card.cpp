#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
vector<int> ans;
vector<int> answer;
int findd(int x) {
	int num = ans.size();
	for (int i = 0; i < num; i++) {
		if (ans[i] == x) return i;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i <  n; i++) {
		long long x;
		cin >> x;
		a.push_back(x);
	}
	for (long long i = 1; i <=  n; i++) {
		vector<int> b;
		vector<int> less;
		b = a;
		for (int j = i - 1; j < b.size(); j++) {
			ans = less;
			int y = findd(b[j]);
			if (y != -1) {
				int g = less.size();
				less.erase(less.begin() + y, less.begin() + less.size());
				less.push_back(b[j]);
			} else less.push_back(b[j]);
		}
		for (int j = 0; j < less.size(); j++) {
			answer.push_back(less[j]);
		}
	}
	sort(answer.begin(), answer.end());
	int num = answer[0], sum = 1;
	for (int i = 1; i < answer.size(); i++) {
		if (answer[i] == num) sum++;
		else {
			cout << sum << ' ';
			sum = 1;
			num = answer[i];
		}
	}
	cout << sum;
	return 0;
}
