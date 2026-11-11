#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
char c;
string s,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a;
		cin>>c;
		for(int j = 1;j <= a;j++){
			s += c;
		}
	}
	int cnt = s.size() / 2 - 1;
	for(int i = 1;i <= s.size();i++){
		x += s[s.size() - i];
	}
	int ans = 0;
	for(int i = 0;i <= cnt;i++){
		if(x[i] != s[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
