#include<bits/stdc++.h>
using namespace std;

int n;//n:字符串分段数量
unsigned long long cnt = 0;//cnt:字符串的位数 
unsigned long long ans = 0;//ans:最少要变动几位 
pair<long long, char>s[2000005] = {};//s[i]-> 第i段的字符数量和字符 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i].first >> s[i].second;
		cnt += s[i].first;
	}
	
	for(int i = 1; i <= cnt / 2; i++){
		int up = 1, down = n;//up:从前往后数指向第几段的字符 down: 从后往前数指向第几段的字符
		int j = i;//j:要找的字符还要再往后数几位
		while(j > s[up].first){
			j -= s[up].first;
			up++;
		} 
		j = i;
		while(j > s[down].first){
			j -= s[down].first;
			down--;
		}
		if(s[up].second != s[down].second)ans++;
	}
	
	cout << ans;
	
	return 0;
}
