#include <bits/stdc++.h>
using namespace std;
bool hw(string s,long long c){
	for ( long long i = 0,j = c - 1 ; i < c / 2 ; i++,j-- ){
		if(s[i] != s[j]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,count = 0,a1,a2;
	string s = "";
	cin>>n;
	for ( long long i = 1 ; i <= n ; i++ ){
		long long t;
		char c;
		cin>>t>>c;
		if(i == 1){
			a1 = t;
		}else if(i == 2)a2 = t;
		count += t;
		for ( long long j = 1 ; j <= t ; j++ ){
			s = s + c;
		}
	}
	if(hw(s,count)){
		cout<<0;
		return 0;
	} else {
		if(n == 2){
			cout<<min(a1,a2);
		} else cout<<n - 1;
	}
	return 0;
} 
