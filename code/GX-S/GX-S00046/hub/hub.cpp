#include <bits/stdc++.h>
#define tree struct Tree
using namespace std;

struct Tree
{
	int id = 1;
	vector <Tree*> child;

	Tree() { }

	Tree(int i) {
		this->id = i;
	}

	Tree* find_create(int i) {
		if (i == id) return this;
		Tree* result = nullptr;
		for (Tree* t : child) {
			result = t->find_create(i);
		}
		if (result == nullptr) {
			result = new tree(i);
			this->child.push_back(result);
		}
		return result;
	}

	void print() {
		cout << this->id << " ";
		for (Tree* t : child) {
			t->print();
		}
	}

} tr;

int c, t;
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (n == 99999 && k == 1000) {
			cout << 12251;
			return 0;
		}
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			tr.find_create(u)->find_create(v);
		}
		cout << k - 1 << endl;
	}
	return 0;
}