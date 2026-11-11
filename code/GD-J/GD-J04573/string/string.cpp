#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n, len = 0, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int a;
		char c;
		cin >> a >> c;
		for(int j = 1; j <= a; j++){
			s += c;
		}
	}
	len = s.size() - 1;
	for(int i = 0; i < len / 2 ; i++){
		if(s[i] != s[len-i])ans ++;
	}
	cout << ans <<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
