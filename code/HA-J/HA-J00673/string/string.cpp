#include<bits/stdc++.h>
using namespace std;
bool huiwen(string f){
	string h = f;
	reverse(h.begin(),h.end());
	if(h == f){
		return 1;
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string a = "";
	for(int i = 1;i <= n;i++){
		int t;
		cin >> t;
		string s;
		cin >> s;
		for(int j = 1;j <= t;j++){
			a = a + s;
		}
	}
	if(huiwen(a)){
		cout << 0;
		return 0;
	}
	int ans = 0,len = a.size();
	for(int i = 0;i < len;i++){
		if(a[i] != a[len - i - 1]){
			if(i >= len / 2){
				break;
			}
			ans++;
		}
	}
	cout << ans;
	return 0;
}
