#include<bits/stdc++.h>
using namespace std;
struct aaa{
	long long a;
	char s;
}a[200005];  
bool check(string s){
	string ss;
	long long t=s.size();
	for(int i=1;i<=t;i++){
		if(s[i]!=s[t+1-i])return 0; 
	}
	return 1; 
}
string gouzao(string s){
	string ss;
	ss=s;
	long long t=s.size()-1;
	for(int i=1;i<=t/2;i++){
		ss[i]=ss[t+1-i];
	}
	return ss;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	string ss;
	ss+=" ";
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].s;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].a;j++){
			ss+=a[i].s;
		}
	}
	if(check(ss)==1){
		cout<<"0";
	}
	if(check(ss)==0){
		string tt=gouzao(ss);
		for(int i=0;i<ss.size();i++){
			if(ss[i]!=tt[i])sum++;
		}
		cout<<sum;
	}
	return 0;
}

