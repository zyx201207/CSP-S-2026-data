#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s1=0;
	string s="";
	cin>>n;
	while (n--){
		int a,k=1;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	if(s.size()%2==0){
		for(int i=0;i<=s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]) s1++;
		}
	}else{
		for(int i=0;i<=s.size()/2-1;i++){
			if(s[i]!=s[s.size()-i-1]) s1++;
		}
	}
	cout<<s1;
	return 0;
}
