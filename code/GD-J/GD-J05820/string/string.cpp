#include<bits/stdc++.h>
using namespace std;
int main(){
	preopen("string.in","w",stdin);
	preopen("string.out","r",strout);
	int n,sum=0;
	string s,m;
	cin>>n;
	for(int i=0;i<n;i++){
	   int x;
	   char a;
	   cin>>x>>a;
	   for(int i=0;i<x;i++){
	   	  s+=a;
	   }
	}
	for(int i=s.size();i>0;i++){
	   m[i]=s[i];
	}
	for(int i=0;i<s.size();i++){
	   if(m[i]!=s[i]){
	   	 sum++;
	   }
	}
	cout<<sum;
	return 0;
}
