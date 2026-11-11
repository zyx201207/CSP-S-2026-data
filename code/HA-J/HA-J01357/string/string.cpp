#include<bits/stdc++.h>
using namespace std;
string s;
char c;
long long n,ans;
int main(){
	cin.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		long long t;
		cin >> t;
		cin >> c;
		for(int i = 0;i < t;i++){
			s += c;
		} 
	}
	for(int i = s.size()-1,j = 0;i >= s.size() - ceil(s.size() / 2)-1;i--,j++){
		if(s[i] != s[j]){
			s[i] = s[j];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
