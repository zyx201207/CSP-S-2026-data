#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s = "";
	cin >> n;
	for (long long i = 1;i <= n;i++){
		long long a;
		string s1;
		cin >> a >> s1;
		for (long long j = 1;j <= a;j++){
			s += s1;
		}
	}
	long long ans=0;
	long long l = s.size();
	if (l % 2 == 0){
		for (long long i = 0;i <= l/2-1;i++){
			if (s[i] != s[l-i-1]){
				ans++;
			}
		}
	}
	else{
		for (long long i = 0;i <= (l-1)/2-1;i++){
			if (s[i] != s[l-i-1]){
				ans++;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
