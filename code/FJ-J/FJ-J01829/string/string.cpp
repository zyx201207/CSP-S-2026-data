#include<bits/stdc++.h>
using namespace std;
int n;
string s, s2;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	while(n--){//ÊäÈë
		int ai;
		string ci;
		scanf("%d", &ai);
		cin >> ci;
		for(int i = 1; i <= ai; i++){
			s += ci;
			s2 += ci;
		}
	}
	reverse(s2.begin(), s2.end());
	if(s == s2){
		cout << 0;
		return 0;
	}
	int l = s.size(), sum = 0;
	for(int i = 0; i < l; i++){
		if(s[i] != s2[i]) sum++;
	}
	cout << sum/2;
	return 0;
}
