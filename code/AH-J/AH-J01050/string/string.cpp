#include<bits/stdc++.h>
using namespace std;
string s,s2;
char c;
long long n,a,len,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(long long j=0;j<a;j++){
			s=s+c;
		}
	}
	s2=s;
	len=s.size();
	for(long long i=0;i<len;i++){
		if(s2[i]!=s[len-i-1]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}
