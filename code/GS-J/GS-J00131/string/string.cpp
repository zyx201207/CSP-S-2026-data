#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s=" ";
	long long  n;
	cin>>n;
	long long d=-1;
	while(n--){
		long long  a;
		string b;
		cin>>a;
		cin>>b;
		for(long long i=0;i<a;i++){
			s+=b;
		}
	}
	long long f=0;
	for(long long i=0;i<s.size();i++){
		f++;
	}
	for(long long i=0;i<s.size();i++){
		if(s[i]!=s[f-i]){
			d++;
		}
	}
	cout<<d;
	return 0;
}
