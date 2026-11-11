//GZ-J00041 贵阳市第二实验中学 吴宇轩
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a;
	char b;
	string s="",n="";
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a >> b;
		s = s.insert(a,b);
	}
	for (int i=s.length()-1; i>=0; i--){
		n += s[i];
	}
	if (s == n){
		cout << 0;
	}
	return 0;
}
