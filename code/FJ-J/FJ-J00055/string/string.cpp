#include <bits/stdc++.h>
using namespace std;
string s="";
long long n,len=0,sum=0;
int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		long long x;
		char c;
		cin >> x >> c;
		for(int j=1; j<=x; j++){
			s+=c;
			len++;
		}
	}
	for(int i=0; i<=len/2; i++){
		if(s[i]!=s[len-i]){
			s[len-i]=s[i];
			sum++;
		}
	}
	cout << sum;
	return 0;
}
/*6
100000000 a
100000000 a
100000000 a
100000000 b
100000000 b
100000000 b*/
