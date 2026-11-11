#include <iostream>
#include <vector>
#include <string> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	scanf("%lld",&n);
	string s;
	for (long long i = 0;i<n;i++){
		long si;string c;
		cin >>si >> c;
		for (long j = 1;j<=si;j++){
			s+=c;
		}
	}
	long l = 0,r = s.length()-1,cnt = 0;
	while (l<=r){
		if (s[l] != s[r])cnt += 1;
		l++;
		r--;
	}
	
	printf("%lld",cnt);
} 
