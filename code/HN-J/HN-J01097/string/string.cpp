#include <bits/stdc++.h>
using namespace std;
long long n;
long long a;
char b;
string s;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(long i=1;i <=n;i++){
		cin>>a>>b;
		for(long j=1;j <=a;j++){
			s+=b;
		}
	}
	long qw;
	qw=s.size();
	for(long i=0;i <=(qw/2);i++){
		if(s[i]!=s[qw-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

 
 
