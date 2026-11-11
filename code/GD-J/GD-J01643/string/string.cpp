#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

const int M = 3000;
long long dp[M][M]; // 把string的i到j变为回文最少需要多少修改 
//pair<char, char> word[M][M];

string s;

void dp_init(){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++){
			dp[i][j] = 6e18;
		}
	}
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	while(n--){
		int a;
		char c;
		cin >> a >> c;
		for(int i = 1; i <= a; i++){
			s += c;
		}
	}
	
	dp_init();
	
	for(int word_len = 1; word_len <= (int)s.size(); word_len++){
		for(int i = 0; i <= (int)s.size() - word_len; i++){
			int j = i + word_len - 1;
			if(word_len == 1) dp[i][j] = 0; // 单个本身就是回文
			else{
				long long before, after; // 往前插入或往后 
				before = dp[i + 1][j];
				if(s[i] != s[j]) before++; // 如果首尾不同，还要再加
				after =  dp[i][j - 1];
				if(s[j] != s[i]) after++;
				if(dp[i][j] > before || dp[i][j] > after){
					//dp[i][j] = min(before, after);
					if(before < after){
						//s[i] = s[j];
						//word[i][j].first = word[i][j].second;
						dp[i][j] = before;
					}
					else{
						//s[j] = s[i];
						//word[i][j].second = word[i][j].first;
						dp[i][j] = after;
					}
				}
				
			} 
		}
	}
	
	int total = (int)s.size();
	cout << dp[0][total - 1];
	return 0;
}
