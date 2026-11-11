#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	char a;
	int b;
	for(int i=0;i<n;i++){
		cin>>b>>a;
		for(int j=0;j<b;j++){
			s+=a;			
		}
	}
	string c=s;
	reverse(s.begin(),s.end());
	if(c==s){
		cout<<0;
	}else{
		int cnt=0;
		string e; 
		for(int i=0;i<s.size();i++){
			if(c[i]!=s[i]){
				if(i<=s.size()/2){
					e+=c[i];
					cnt++;
				} 
			}else{
				e+=s[i];
			}
		}
		int sum=0;
		string m;
		for(int i=0;i<s.size();i++){
			if(c[i]!=s[i]){
				if(i<=s.size()/2){
					e+=s[i];
					sum++;
				} 
			}else{
				e+=c[i];
			}
		}
		cout<<min(sum,cnt);
	}
	
}
