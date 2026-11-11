#include <bits/stdc++.h>
using namespace std;
string s,a,b;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m;
	char c;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>m>>c;
		for(long long i=0;i<m;i++){
			s+=c;
		}
	}
	if(s.size()%2==0){
		for(long long  i=0;i<s.size()/2;i++){
			a+=s[i];
		}
		if(s==a+a){
			cout<<"0";
		}else{
			cout<<a.size();
		}
	}else{
		for(long long i=0;i<(s.size()-1)/2;i++){
			b+=s[i];
		}
		if(s==b+b+s[(s.size()-1)/2]){
			cout<<"0";
		}else{
			cout<<b.size();
		}
	}
	return 0;
}
