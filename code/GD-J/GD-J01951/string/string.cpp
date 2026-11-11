#include<bits/stdc++.h>
using namespace std;
string fz(string s){
	string s2="";
	for(int i=s.size()-1;i>=0;i--){
		s2=s2+s[i];
	}
	return s2;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>>n;
	for(int i=0;i<n;i++){
		char c;int a;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s=s+c;
		}
	}
	int len=s.size();
	string s2=fz(s);
	long long sum=0;
	for(int i=0;i<len;i++){
		if(fz(s2)==s2){
			cout<<sum;
			break;
		}
		if(s[i]!=s2[i]){
			s2[i]=s[i];
			sum+=1;
		}
	}
	return 0;
}
