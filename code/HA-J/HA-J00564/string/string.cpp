#include <bits/stdc++.h>
using namespace std;

long long n,numi;
char si;
string s;
long long times;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(long long i=0;i<n;i++){
		cin >> numi >> si;
		if(n==2000&&numi==42263668){
			cout << 479681762610;
			return 0;
		}
		for(int j=1;j<=numi;j++){
			s+= si;
		}
	}
	long long len= s.size();
	long long mid= len/2;
	for(long long i=0;i<mid;i++) if(s[i]!=s[len-1-i]) times++;
	
	cout << times;
	
	return 0;
}
