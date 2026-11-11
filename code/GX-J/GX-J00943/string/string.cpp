#include<bits/stdc++.h>
using namespace std;
bool f(string a){
	string c;
	for(int i=a.size()-1;i>=0;i--)c+=a[i];
	if(c==a)return 1;
	else return 0;
	}
string a;
char b;
long long n,s,s1ze;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>s>>b;
		s1ze+=s;
		for(long long j=0;j<s;j++)a+=b;
		}
	if(f(a)){cout<<0;return 0;}
	for(long long i=s1ze-1;i>=0;i--){
		a[i]=a[1];
		if(f(a)){cout<<i-1;return 0;}
		}
	return 0;
	}
