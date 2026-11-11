#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long a;
	long long t=0;
	char c;
	cin>>n;
	string s="";
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++)
			s+=c;
	}
	long long l=s.size();
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1])
			t++;
		}
	cout<<t;
	return 0;
}
