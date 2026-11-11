#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char b[200005];
string s;
long long ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for (long long j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for (long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[n-i+1]){
			ss++;
		}
	}
	cout<<ss;
}
