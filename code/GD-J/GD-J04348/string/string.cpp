#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >> n;
	string s;
	for(int i = 0 ; i < n ; i++){
		int sum;
		char c;
		cin >> sum >> c;
		while(sum--) s += c;
	}
	int ans = 0;
	for(int i = 0 ; i < s.size() / 2 ; i++){
		if(s[i] != s[s.size() - 1 - i]) ans++;
	}
	cout << ans << '\n';
	/*int n , len = 0;
	cin >> n;
	vector<pair<ll , char>> inp;
	for(int i = 0 ; i < n ; i++){
		ll sum;
		char c;
		cin >> sum >> c;
		if(inp.size() > 1 && inp.back().second == c) inp.back().first += sum; 
		else inp.push_back({sum , c});
		len += sum;
	}
	bool tr = len % 2;
	len /= 2;
	int time = 0 , i = 0;
	vector<pair<ll , char>> left;
	bool flag = false;
	int sy = 0;
	while(true){
		if(time + inp[i].first <= len){
			time += inp[i].first;
			left.push_back(inp[i]); 
		}
		else{
			left.push_back({len - time , inp[i].second});
			sy = inp[i].first - len + time;
			flag = true;
			break;
		}
		i++;
		if(time == len){
			i--;
			break;
		}
	}
	time += inp[i].first;
	i++;
	vector<pair<ll , char>> right;
	while(i < inp.size()){
		if(flag){
			if(sy > 1) right.push_back({sy - tr, inp[i - 1].second});
			flag = false;
		}
		right.push_back(inp[i]);
		i++;
	}
	cout << '\n';
	for(pair<ll , char> t : left) cout << t.first << ' ' << t.second << '\n';
	cout << '\n';
	for(pair<ll , char> t : right) cout << t.first << ' ' << t.second << '\n';
	*/
	return 0;
}
