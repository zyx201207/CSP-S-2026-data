#include <bits/stdc++.h>
using namespace std;
int n,cnt,a[200010],flag,cs = 1;
char c[200010];
string s;
int main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		if(i != 1 && a[i] != a[i-1]){
			flag = 1;
		}
	}
	if(!flag){
		cs = a[1];
		for(int i = 1;i <= n;i++){
			a[i] = 1;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i];j++){
			s += c[i];
		}
	}
	for(int i = 0,j = s.size() - 1;i < j;i++,j--){
		if(s[i] != s[j]){
			cnt++;
		}
	}
	cout << cnt * cs;
	return 0;
}
