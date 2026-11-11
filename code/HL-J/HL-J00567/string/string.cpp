#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	while(n--){
		int a;
		string k;
		cin >> a >> k;
		while(a--){
			s+=k;
		}
	}
	string k;
	k = s;
	reverse(k.begin(),k.end());
	int cnt = 0;
	for(int i = 0;i < s.size();i++){
		if(k[i] != s[i]) cnt++;
	}
	cout << cnt/2;
	return 0;
}
