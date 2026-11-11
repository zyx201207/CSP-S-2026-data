#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
vector<pair<char, long long>> chrs;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long lsum = 0;
	for(int i = 1; i <= n; i++){
		long long v;
		char c;
		cin >> v >> c;
		chrs.push_back({c, v});
		lsum += v;
	}
	long long ans = 0, h = lsum / 2;
	for(auto its = chrs.begin(), ite = chrs.end() - 1;its < ite && its->second > 0 && ite->second > 0;){
		long long sl = min(its->second,ite->second);
		its->second -= sl, ite->second -= sl;
		if(its->first != ite->first) {
			ans += sl;
		}
		if(its->second == 0) its++;
		if(ite->second == 0) ite--; 
	}
	cout << ans;
	return 0;
} 
