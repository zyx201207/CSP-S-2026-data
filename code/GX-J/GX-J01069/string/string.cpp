#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long n,jg=0;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long x;
		cin>>x;
		string t="";
		cin>>t;
		while(x--){
			s+=t;
		}
	}
	long long x=s.size()/2;
	for(long long i=0;i<x;i++){
		if(s[i]!=s[s.size()-i-1]){
			jg++;
		}
	}
	cout<<jg;
	return 0;
}
