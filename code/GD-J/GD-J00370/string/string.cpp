#include<bits/stdc++.h>
using namespace std;
string s,aa,bb;
int n=0,sum=0;
bool bl=true,by=true; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		long long a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	for(int i=1;i<=s.size();i++){
		if(s[i]!=s[i-1]){
			bl=false;
		}
	}if(bl==true){
		cout<<"0";
		return 0;
	}
	
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2;i++){
			aa+=s[i];
		}
		for(int i=s.size()-1;i>=s.size()/2;i--){
			bb+=s[i];
		}
		for(int i=0;i<s.size()/2;i++){
			if(aa[i]!=bb[i]){
				by=false;
				sum++;
			}
		}
		if(by==false){
			printf("%d",sum);
			return 0;
		}
		if(by==true){
			cout<<"0";
			return 0; 
		}
	}else if(s.size()%2!=0){
		for(int i=0;i<(s.size()-1)/2;i++){
			aa+=s[i];
		}
		for(int i=s.size()-1;i>=(s.size()+1)/2;i--){
			bb+=s[i];
		}
		for(int i=0;i<(s.size()-1)/2;i++){
			if(aa[i]!=bb[i]){
				by=false;
				sum++;
			}
		}
		if(by==false){
			printf("%d",sum);
			return 0;
		}
		if(by==true){
			cout<<"0";
			return 0; 
		}
	}
	return 0;
} 
