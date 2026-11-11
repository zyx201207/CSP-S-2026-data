#include <bits/stdc++.h>
using namespace std;
int n,a[200002],ok = 1;
char c[200002];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j++)
			s += c[i];
	}
	for(int i = 0,j = s.size() - 1;i != j;i++,j--)
		if(s[i] != s[j]){
			ok = 0;
			break;
		}
	if(ok)
		cout << "0\n";
	else
		cout << "1\n";
	return 0;
}
//CCF please let me AC!!!
