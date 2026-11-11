#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1){
		cout<<0;
		return 0;
	}
	if(n<=2){
		while(n--){
			long long a=0;
			string b;
			cin>>a>>b;
			for(long long i=1;i<=a;i++){
				s+=b;
			}
		}
		string s1;
		for(long long i=s.size()-1;i>=0;i--){
			s1+=s[i];
		}
		if(s==s1){
			cout<<0;
		}
		else cout<<2;
	}
	return 0;
} 
