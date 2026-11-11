#include <bits\stdc++.h>
using namespace std;
string s="",c="";
long long cnt;
int main() {
	freopen("string.in","r",stetin);
	int t;
	char b;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long a;
		cin>>a;
		cin>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	} 
	for(int i=s.size()-1;i>=0;i--){
		c+=s[i];
	}
	//cout<<s<<"\n"<<c;
	for(int i=1;i<=s.size();i++){
		if(s[i]!=c[i])cnt++;
	}
	cout<<cnt/2+cnt%2;
	freopen("string.out","w",sgtout);
	return 0;
}
