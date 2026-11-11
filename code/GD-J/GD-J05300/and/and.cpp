#include<bits/stdc++.h>
using namespace std;
long long n,m,ma;
long long cf12(long long lk,long long i){
	long long x=1;
	for(long long j=0;j<=i;j++){
		x*=lk;
	}
	return x;
}
string f2(long long q){
	string se,se1;
	while(q){
		
		if(q%2==0)se+="0";
		else se+="1";
		q/=2;
	}
	//for(long long i=se.size()-1;i>=0;i--)se1+=se[i];
	
	return se;
}
long long f10(string s){
	long long x=0;
	for(long long i=0;i<s.size();i++){
		
		x+=(s[i]-48)*cf12(2,i-1);
		
	}
	return x;
}
long long f(long long q1,long long q2){
	string s1,s2,s3;
	s1=f2(q1);
	s2=f2(q2);
	if(s1.size()>s2.size()){
		for(long long i=0;i<s1.size();i+=1){
			if(i>=s2.size())s3+=s1[i];
			else if(s1[i]=='0' || s2[i]=='0')s3+='0';
			else s3+='1';
		} 
	}
	else{
		for(long long i=0;i<s2.size();i+=1){
			if(i>=s1.size())s3+=s2[i];
			else if(s1[i]=='0' || s2[i]=='0')s3+='0';
			else s3+='1';
		}
	}
	return f10(s3);
} 

int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+23]={0};
	for(long long i=0;i<n;i++){
		cin>>a[i];
		
	}
	cout<<f(12,3);
	
	
	
	
} 
