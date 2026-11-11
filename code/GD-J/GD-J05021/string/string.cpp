#include <iostream>
#include <string>
using namespace std;
string s = "";
char c;
long long n,a;
long long func(string s){
	long long cnt = 0;
	for(size_t i = 0;i < s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])cnt++;
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--){
		cin >> a >> c;
		while(a--)s+=c;
	}
	cout << func(s);
	return 0;
}
