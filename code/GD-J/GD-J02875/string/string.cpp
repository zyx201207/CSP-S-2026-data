#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin >> n;
	while(n--){
		int a;
		string c;
		cin >> a >> c;
		while(a--){
			s = s + c;
		}
	}
	int len = s.size();
	s = ' ' + s;
	for(int i = 1;i <= len / 2; i++){
		if(s[i] != s[len + 1 - i]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
