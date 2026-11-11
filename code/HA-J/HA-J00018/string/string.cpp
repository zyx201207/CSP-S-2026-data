#include <bits/stdc++.h>
using namespace std;

int n,cnt,tmp;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin >> a >> c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	string s1=s;
	for(int i=0;i<s.size()/2;i++) {
		s1[s.size()-i-1]=s1[i];
	}
	for(int i=1;i<s.size();i++) {
		if(s[i]!=s1[i])	cnt++;
	}
	cout << cnt;
	return 0;
}
