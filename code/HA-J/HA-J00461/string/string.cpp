#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,xxxxi=0,cnt=0;
	string s="";
	cin>>n;
	while(xxxxi<n){
		xxxxi++;
		int a;
		char w;
		cin>>a>>w;
		for(int i=0;i<a;i++){
			s+=w;
		}
	}for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])cnt++;
	}cout<<cnt;
}
