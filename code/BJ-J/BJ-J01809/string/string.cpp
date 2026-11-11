#include<bits/stdc++.h>
using namespace std;	
string s,sf;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=0;
	cin>>n;for(int i=0;i<n;i++){
		int a;
		char ch;
		cin>>a>>ch;
		for(int j=i;j<a+i;j++)s[i+j]=a;
	}
	for(int i=s.size();i>0;i--)sf[s.size()-i]=s[i];
	while(1){
		for(int i=s.size();i>0;i--){
			if(s[i]!=s[s.size()-i]){
				s[i]=s[s.size()-i];
				num++;}
			}
		for(int i=s.size();i>0;i--)sf[i]=s[s.size()-i];
		if(s==sf){
		cout<<num;
		return 0;}
		}
	}
