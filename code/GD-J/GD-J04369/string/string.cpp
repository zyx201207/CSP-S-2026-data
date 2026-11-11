#include<bits/stdc++.h>
using namespace std;
long long n,l=0,k=0;
string s1,s2;
long long fun(string s){
	long long m=0,p=s.size()-1,o=0;
	for(long long i=1;i<=(s.size())/2;i++){
		if(s[m]!=s[p]){
			o++;
		}
	}
	return o;
}
int main(){
	cin>>n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=n;++i){
		cin>>l>>s1;
		k+=l;
		for(int i=1;i<=l;++i){
			s2+=s1;
		}
	}
	cout<<fun(s2);
	return 0;
}
