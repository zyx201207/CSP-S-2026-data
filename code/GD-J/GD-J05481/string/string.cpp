#include <bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n = 0;
	long long ans = 0;
	cin >> n;
	vector<string> ch;
	auto dfs = [&] (auto &&self, string choose, int i){
		if(i == n - 1){
			ch.push_back(choose);
			return;
		}
		choose[i] = '0';
		self(self, choose, i + 1);
		choose[i] = '1';
		self(self, choose, i + 1);
	};
	string s;
	deque<pair<char, long long>> d;
	auto make_s = [&](char c, long long cnt){
		string s_r;
		for(int i = 0;i < cnt;i++){
			s_r += c;
		}
		return s_r;
	};
	for(int i = 0;i < n;i++){
		long long cnt = 0;
		char c;
		cin >> cnt >> c;
		d.push_back({c, cnt});
		s += make_s(c, cnt);
	}
	dfs(dfs,make_s(0, n - 1), 0);
	long long pos = 0;
	for(int k = 0;k < ch.size();k++){
		long long res = 0;
		string cs = ch[k]; //决策
		for(int i = 0;i < cs.size() ;i++){
			auto left = d.front();
			auto right = d.back();
			char c;
			int nums = 0;
			if(cs[i] == '0'){ //选择左边 
				d.pop_front();
				nums = left.second;
				c = left.first;
			}
			else{ //选择右边 
				d.pop_back();
				nums = right.second;
				c = right.first;
			}
			for(int j = pos;j < pos + nums;j++){
				if(s[j] == c) continue;
				res ++;
			}
			pos += nums;
		} 
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}
