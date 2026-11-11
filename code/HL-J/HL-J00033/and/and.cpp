#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,k,c[33],cnt;
vector<int> v[33];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> k;
	for(int i = 1,x; i <= n; i++){
		cin >> x;
		int y = x;
		string s = "";
		while(x){
			if(x & 1) s += '1';
			else s += '0';
			x >>= 1;
		}
		for(int j = 0; j < s.size(); j++){
			if(s[j] == '1') {
				c[j + 1]++;
				v[j + 1].push_back(y);
			}
		}
	}
	for(int i = 32; i > 0; i--){
		if(c[i] >= k){
			sort(v[i].begin(),v[i].end(),greater<int>());
			int ans = v[i][0];
			for(int j = 1; j < k; j++) ans &= v[i][j];
			cout << ans;
			break;
		}
	}
	return 0;
}