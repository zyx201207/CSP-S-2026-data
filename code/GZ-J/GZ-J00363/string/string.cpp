//贵阳市第三中学 游子乐GZ-J00363 
#include <bits/stdc++.h>
using namespace std;

long long n,cnt = 0,tot = 0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long x;
	string s;
	char c;
	for(int i = 1;i <= n;i++){
		cin >> x >> c;
		for(int j = 1;j <= x;j++){
			s += c;
		}
	}
	if(s.size() % 2 == 0){
		string t;
		long long len = s.size() / 2;
		for(int i = 0;i < len;i++){
			t += s[i];
		}
		reverse(t.begin(),t.end());
		for(int i = 0;i < len;i++){
			if(s[i+len] != t[i]) cnt++;	
		}
		cout << cnt;
		return 0;
	}else{
		string t;
		long long len = s.size() / 2;
		for(int i = 0;i < len;i++){
			t += s[i];
		}
		reverse(t.begin(),t.end());
		for(int i = 0;i < len;i++){
			if(s[i+len+1] != t[i]) tot++;
		}
		cout << tot;
	}
	return 0;
}
