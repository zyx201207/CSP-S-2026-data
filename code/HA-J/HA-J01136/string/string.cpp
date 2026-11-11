#include <bits\stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	string h,s="";
	long long a,b,q=0;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b;
		cin>>h;
		for(int j=0;j<b;j++){
			s+=h;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			q++;
		}
	}
	cout<<q;
	return 0;
}
