#include<iostream>
#include<string>
using namespace std;
#define ll long long
string fz(string s){
	string s2="";
	for(ll i=1;i<s.length();i++){
		s2+=s[s.length()-i-1];
	}
	return s2;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n,t;
	cin>>n;
	char ins;
	for(int i=1;i<=n;i++){
		cin>>t>>ins;
		for(int j=0;j<t;j++) s+=ins;
	}
	bool two=0;
	ll num=0;
	if(s.length()%2==1){//去中间
		two=1;
		for(int i=s.length()/2;i<s.length();i++){
			s[i]=s[i+1];
		}
	}
	string s2=fz(s);
	for(int i=0;i<(s.length()-two)/2;i++){
		if(s[i]!=s2[i]){
			num+=1;
			cout<<s[i]<<" "<<s2[i]<<endl;
		}
	}
	cout<<num;
	return 0;
}

