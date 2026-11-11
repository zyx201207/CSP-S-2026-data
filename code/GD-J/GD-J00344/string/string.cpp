#include<bits/stdc++.h>
using namespace std;
string s;
long long n,x,l;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> x >> c;
		while(x--){
			s += c;
		}
	}
	long long cnt = 0;
	for(long long i = 0;i < s.size() / 2;i++){
		if(s[i] != s[s.size() - i - 1])cnt++;
		//cout << s[i] << s[s.size() - i - 1] << '\n';
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
