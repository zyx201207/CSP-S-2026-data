#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'

using namespace std;

const int dirx[] = {0, 1, -1, 0};
const int diry[] = {1, 0, 0, -1};
int tr1, tr2;
string id1, id2;
map<char, int> line = {
	{'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'F', 5}
}, side = {
	{'A', 1}, {'B', 1}, {'C', 1}, {'D', 2}, {'F', 2}
};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> tr1 >> id1 >> tr2 >> id2;
	
	int col1 = 0, line1 = 0, col2 = 0, line2 = 0, side1 = 0, side2 = 0;
	char c, cc;
	sscanf(id1.c_str(), "%d%c", &col1, &c);
	sscanf(id2.c_str(), "%d%c", &col2, &cc);
	line1 = line[c], line2 = line[cc];
	side1 = side[c], side2 = side[cc];
	
	cout << (tr1 == tr2);
	cout << (tr1 == tr2 && col1 == col2);
	cout << (tr1 == tr2 && col1 == col2 && side1 == side2);
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		int tx = col1 + dirx[i], ty = line1 + diry[i];
		if (tx == col2 && ty == line2) {
			flag = true;
			break;
		}
	}
	cout << (tr1 == tr2 && col1 == col2 && side1 == side2 && flag) << endl;
	return 0;
}
