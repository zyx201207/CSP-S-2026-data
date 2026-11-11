#include<bits/stdc++.h>
using namespace std;
string a;
long long t;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>t>>b;
		for(long long j=1;j<=t;j++){
			a+=b;
		}
	}
	string b=a;
	reverse(a.begin(),a.end());
	long long s=0;
	for(long long i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			s++;
		}
	}
	cout<<s/2;
	return 0;
}
