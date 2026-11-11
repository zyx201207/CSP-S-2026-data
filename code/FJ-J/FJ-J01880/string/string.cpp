#include <bits/stdc++.h>
using namespace std;
long long a[10006];
char c[1000007];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	string s;
	long long num = 0,num1 = 0;
	for(long long i = 0;i < n;i++){
		cin >> a[i] >> c[i];
		num1 += a[i];
//		for(long long j = 0;j < a[i];j++){
//			s += c[i];
//		}
	}
	if(num1 <= 1000000){
		for(long long i = 0;i < n;i++){
			for(long long j = 0;j < a[i];j++){
				s += c[i];
			}
		}
		int v = s.length();
		for(int i = 0;i <= v / 2 - 1;i++){
			if(s[i] != s[s.length() - 1 - i]){
				s[s.length() - 1 - i] = s[i];
				num++;
			}
		}
		cout << num;
		return 0;
	}else{
		num1 /= 2;
	for(int i = 0;i <= n/2-1;i++){
		if(a[i] == a[n-1-i] && c[i] != c[n-1-i]){
			num += a[i];
		}else if(c[i] == c[n-1-i]){
			continue;
		}else{
			num += max(a[i],a[n-1-i]);
		}
	}
	cout << min(num,num1);
	}
//	num1 /= 2;
//	for(int i = 0;i <= n/2-1;i++){
//		if(a[i] == a[n-1-i] && c[i] != c[n-1-i]){
//			num += a[i];
//		}else if(c[i] == c[n-1-i]){
//			continue;
//		}else{
//			num += max(a[i],a[n-1-i]);
//		}
//	}
//	cout << min(num,num1);
//	return 0;
//	int v = s.length();
//	for(int i = 0;i <= v / 2 - 1;i++){
//		if(s[i] != s[s.length() - 1 - i]){
//			s[s.length() - 1 - i] = s[i];
//			num++;
//		}
//	}
//	cout << num;
	return 0;
}
