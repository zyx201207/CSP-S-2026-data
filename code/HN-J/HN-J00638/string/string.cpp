#include<bits/stdc++.h>
using namespace std;
const int N=+5;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	char s1;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cin>>s1;
		for(int j=0;j<x;j++){	
			s+=s1;
		}
	}
	int lens=s.size()-1;
	int cnt=0;
	string s2;
	for(int i=0;i<s.size();i++){
		s2=s;
		reverse(s2.begin(),s2.end());
		if(s==s2){
			cout<<cnt;
			return 0;
		}
		if(s[i]!=s2[i]){
			s[lens]=s2[lens];
			cnt++;
			lens--;
		}
		
	}
	return 0;
} 
