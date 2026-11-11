#include<bits/stdc++.h>
using namespace std;
string s="",c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(long long j=1;j<=n;j++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long i=1;i<=a;i++){
			s+=char(b);
		}
	}
	c=s;
	long long cnt=0;
	reverse(s.begin(),s.end());
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=c[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
