#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define int long long
int n, a[(int)2e5 + 5], sum = 0, st[(int)2e5 + 5];
char c[(int)2e5 + 5];
vector<int> line;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		st[i] = sum + 1;
		sum += a[i];
	}
	map<int, char> mp;
	for(int i = 1;i <= n;i++){
		if(st[i] <= (sum + 1) / 2ll){
			line.push_back(st[i]);
		}
		if(st[i] + a[i] - 1 >= (sum + 1) / 2ll){
			line.push_back(sum - st[i] - a[i] + 2);
		}
	}
	//for(int i = 1;i <= n;i++) cout << st[i] << ' ';
	//cout << '\n';
	sort(line.begin(), line.end());
	line.erase(unique(line.begin(), line.end()), line.end());
	//for(int i : line){
	//	cout << i << ' ';
	//} cout << '\n';
	int cnt = 0;
	for(int i = 0;i < line.size();i++){
		int pos1 = upper_bound(st + 1, st + n + 1, line[i]) - st - 1;
		int pos2 = upper_bound(st + 1, st + n + 1, sum - line[i] + 1) - st - 1;
		// cout << line[i] << pos1 << pos2 << c[pos1] << c[pos2] << '\n';
		if(c[pos1] != c[pos2]){
			cnt+=(i == line.size() - 1? (sum + 1) / 2 + 1: line[i + 1]) - line[i];
		}
		//cout << cnt << '\n';
	}
	cout << cnt;
	return 0;
}
	
