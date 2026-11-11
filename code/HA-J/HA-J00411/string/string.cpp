#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char c;
int a;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int ans=0;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
			s[i]=s[s.size()-1-i];
		}
	}
	cout << ans;
	
	
	return 0;
}
