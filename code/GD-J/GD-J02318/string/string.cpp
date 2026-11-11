#include <bits/stdc++.h>
using namespace std;
string s = "";

bool st(long long o,long long p){
	if(s[o] != s[p]) return false;
	return true;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	
	for(int i=0;i < n;i ++){
		long long x;
		char x2;
		cin >> x >> x2;
		for(long long j=0;j < x;j ++){
			s += x2;
		}
	}
	
	long long sum = 0;
	long long x = s.size();
	
	for(long long i=0;i < x / 2;i ++){
		long long num = x - i - 1;
		bool s2 = st(i,num);
		if(!s2){
			s[num] = s[i];
			sum ++;
		}
	}
	cout << sum;
	
	
	return 0;
}
