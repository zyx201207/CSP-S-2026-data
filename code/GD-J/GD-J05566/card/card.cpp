//4 3
//1 2 1 3
#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card1.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <int> cnt(m, 0);
	vector <char> list(n, '0');
	for (int i = 0; i < n; i++) cin >> list[i];
	for (int z = 0; z < n; z++){
		string s;
		for (int i = z; i < n; i++){
			if (s.find(list[i]) == string::npos) s.push_back(list[i]);
			else s = s.substr(0, s.find(list[i]));
		}
		for (int i = 0; i < m; i++){
			if (s.find(i + '0') != string::npos) cnt[i]++;
		}
	}
	for (int i = 0; i < m; i++) cout << cnt[i] << ' ';
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
