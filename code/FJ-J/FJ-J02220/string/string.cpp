#include<bits/stdc++.h>
using namespace std;
long long gs;
char a;
string s;
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(long long i = 1; i <= n; i++){
		cin >> gs >> a;
		for(long long j = 1; j <= gs ; j++){
			s += a;
		}
	}
	for(long long i = 0 , j = n - 1; i < n , j >= 0; i++ , j--){
		if(s[i] != s[j]){
			cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}
