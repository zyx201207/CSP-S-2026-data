#include <bits/stdc++.h>
using namespace std;
long long n,a[200001],f=0;
string b[200001],s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(long long j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			f++;
		}
	}
	cout<<f;
	return 0;
}
