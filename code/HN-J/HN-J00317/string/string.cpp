#include<bits/stdc++.h>
using namespace std;
string s;
long long n,len,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(long long i=1;i<=n;i++){
		long long a;char c;
		cin >>a>>c;
		len+=a;
		for(long long j=1;j<=a;j++) s+=c;
	}
	for(long long i=0;i<len/2;i++)
		if(s[s.size()-1-i]!=s[i]) cnt++;
	cout <<cnt;
	return 0;
}
