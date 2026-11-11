#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m = 0;
	cin >> n;
	string s = " ";
	for (int i = 1;i <= n;i++){
		int x;
		char tp;
		cin >> x >> tp;
		for (int j = 1;j <= x;j++)
			s = s + tp;
		m += x;
	} 
	int ans = 0;
	for (int i = 1;i <= m/2;i++)
		if(s[i] != s[m - i + 1])
			ans++;
	printf("%d",ans);
	return 0;
}
