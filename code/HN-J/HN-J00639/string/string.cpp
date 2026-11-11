/*#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum,ans,c=0;
	string s,n="";
	cin>>sum;
	for(int i=0;i<sum;i++){
		cin>>ans;
		cin>>s;
		for(int j=0;j<ans;j++){
			n+=s;
		}
}
	s=n;
	reverse(s.begin(),s.end());
	if(s==n){
		cout<<c<<endl;
		return 0;
	}	else{
		for(int i=0;i<s.size()/2+1;i++){
			if(s[i]!=n[i]){
				s[i]=n[i];
				c++;
			}
		}
	}
	cout<<c<<endl;
	return 0;
} 
//1000000000 a
