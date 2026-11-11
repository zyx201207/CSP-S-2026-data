#include <iostream>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum = 0;
	string s = "";
	cin >> n;
	for(int i = 0;i < n;i++){
		int a; char c;
		cin >> a >> c;
		for(int j = 0 ;j < a;j++) s += c;
	}
	for(int i = 0;i < s.size() / 2;i++) if(s[i] != s[s.size() - i - 1]) sum++;
	cout << sum << endl;
	return 0;
}
