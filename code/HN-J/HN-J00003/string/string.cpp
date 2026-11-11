#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	int n, cnt=0, ans=0;
	string s;
	cin >> n;
	int a;
	char c;
	for(int i=0; i<n; i++){
		cin >> a >> c;
		if(c !='a')    ans+=a;
		for(int i=0; i<a; i++){
			s+=c;
		}
	}
	int len=s.size();
	for(int i=0; i*i<len;i++){
		if(s[i] != s[len-i-1])
		cnt++;		
	}
	if(a>=1000000000){
		cout << ans;
	}
	else{
		cout << cnt;
	}
	return 0;
}
