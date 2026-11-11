#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin >> n;
	string s;
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin >> a >> b;
		for(int i=1;i<=a;i++){
			s += b;
		}
	}
	long long L = s.size();
	for(int i=0;i<L/2;i++){
		if(s[i] != s[L+1-i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
