#include<bits/stdc++.h>
using namespace std;
string s,s1;
char b;
int n,a;
void ss(int x,char y){
	for(int i=0;i<a;i++){
		s+=b;
	}
	return;
}
string ss2(string x){
	string y="";
	int L=x.size(); 
	while(L--){
		y+=x[L];
	}
	return y;
}
int ss3(string x,string y){
	int sum=0;
	for(int i=0;i<x.size()/2;i++){
		if(x[i]!=y[i]){
			sum++;
		}
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		ss(a,b);
	}
	s1=ss2(s);
	int sum=ss3(s,s1);
	cout<<sum;
	return 0;
}
