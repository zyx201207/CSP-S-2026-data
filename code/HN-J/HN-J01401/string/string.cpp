#include <bits/stdc++.h>
using namespace std;
int n,ans,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--){
		int a;
		string c;
		cin >> a >> c;
		for(int i = 0; i <= a ;i++){
			s += c;
		}
		ans += a;
	}
	for(int i = 0; i < ans/2;i++){
		if(s[i] != s[ans-i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
