#include<bits/stdc++.h>
using namespace std;
struct str{
	long long a;
}; 
long long str[110];
int main(){
	cin.tie(0);
	int n;
	cin>>n;
	string s="";
	while(n--){
		long long a1;
		char c;
		cin>>a1>>c;
		s+=c;
		str[c]+=a1;
	}
	long long sum=0;
	int j=s.length();
	string s2="";
	for(int i=j-1;i>=0;i--){
		s2+=s[i];
	}
	if(s2==s){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=s.length();i++){
		if(s[i]!=s[j]){
			if(s[i+1]==s[i] || s[j-1]==s[j]){
				continue;
			}
			sum+=str[s[i]];
		}
		j--;
	}
	
	cout<<sum;
	
	return 0;
}
