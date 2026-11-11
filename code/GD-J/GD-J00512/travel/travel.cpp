#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("teavel.in","r",stdin);
	freopen("teavel.out","w",stdout);
	string s;
	string s2;
	string s1;
	string s3;
	int a,b=1,c=1,d=0;
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		a=1;
	}
	else{
	cout<<"0000";
	return 0;
	}
	int l=s1.size();
	for(int i=0;i<l-1;i++){
		if(s1[i]!=s3[i]){
			cout<<a<<"000";
			return 0; 
		}
	}
	int n=s1[l-1]-'A'+1;
	int m=s3[l-1]-'A'+1;
	if(m-n>=3){
		cout<<"1100";
		return 0;
	}
	n++;
	if(n==m){
		d=1;
	}
	cout<<a<<b<<c<<d;
} 
