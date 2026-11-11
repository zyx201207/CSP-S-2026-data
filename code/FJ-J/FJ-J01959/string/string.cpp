#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
int cnt, n, a;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i = 1;i <= n;i++){
		string x;
		cin >>a>>x;
		for(int i = 1;i <= a;i++){
			s+=x;
		}
	}int t = s.size(); 
	for(int i = 0;i < t;i++){
		if(s[i]!=s[t-i-1]){
			cnt++;
			s[i] = s[t-i-1]; 
		}
	}cout<<cnt;
	return 0;
}
