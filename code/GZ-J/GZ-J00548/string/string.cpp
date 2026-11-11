//GZ-J00548   遵义四中 王睿博
#include <bits/stdc++.h>
using namespace std;

long long n , x , ans = 0;
char a;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--){
		cin >> x >> a;
		while(x--){
			s += a;
		}
	}
	long long len = s.size() - 1;
	for(int i = 0 ; i <= len / 2 ; i++){
		if(s[i] != s[len - i]){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
