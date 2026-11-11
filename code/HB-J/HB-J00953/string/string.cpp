#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m = 0;
	string s;
	cin >> n;
	for(long long i = 1;i <= n;i++){
		long long num;
		char zf;
		cin >> num;
		cin >> zf;
		for(long long j = 1;j <= num;j++){
			s += zf;
		}
	}
	long long shu = s.size();
	long long j = shu - 1;
	for(long long i = 0;i < shu / 2;i++){
		if(s[i] != s[j]){
			m += 1;
		}		
		j -= 1;
	}	
	cout << m;
	return 0;
}
