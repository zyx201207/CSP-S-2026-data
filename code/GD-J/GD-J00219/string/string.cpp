#include <bits/stdc++.h>
using namespace std;
long long n;
long long tot;
long long ans;
long long l, r;
struct node{
	char c;
	long long cs;
	long long zuo, you;
}str[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for(long long i = 1; i <= n; i++){
		cin >> str[i].cs >> str[i].c;
		str[i].zuo = tot + 1;
		str[i].you = tot + str[i].cs;
		
		tot += str[i].cs;
//		cout << str[i].zuo << " " << str[i].you << "\n";
	}
	
	l = 1, r = n;
	while(1){
//		cout << l << " " << r << "\n";

		if(l >= r){
			break;
		}
		long long tor_l = tot + 1 - str[l].you;
		long long tor_r = tot + 1 - str[l].zuo;

		long long jj = min(str[r].you, tor_r) - max(str[r].zuo, tor_l) + 1;
		
		if(str[l].c != str[r].c){
			ans += jj;
		}
		
		if(tor_l == str[r].zuo){
			l++, r--;
		}
		else if(tor_l < str[r].zuo){
			r--;
		}
		else if(tor_l > str[r].zuo){
			l++;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
