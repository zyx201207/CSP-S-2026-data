#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct k{
	ll num;
	char c;
};
ll ans;
int n;
string cur, spcur;
vector<k> save;
int main(){
	ios::sync_with_stdio(nullptr);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	bool f = true, f2 = true;
	char lyc = '5';
	ll lyn = -500;
	for(int i = 1; i <= n; i++){
		ll num;
		char c;
		cin >> num >> c;
		if(i > 1) f &= (c == lyc);
		if(i > 1) f2 &= (num == lyn);
		lyc = c, lyn = num;
		save.push_back({num, c});
		spcur += c;
	}
	
	if(f){
		cout << 0;
		return 0;
	}
	if(f2){
		int splen = spcur.size();
		for(int i = 0; i < splen / 2; i++){
			if(spcur[i] != spcur[splen - i - 1]){
				ans += lyn;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 0; i < save.size(); i++){
		for(int j = 1; j <= save[i].num; j++){
			cur += save[i].c;
		}
	}
	int len = cur.size();
	for(int i = 0; i < len / 2; i++){
		if(cur[i] != cur[len - i - 1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
