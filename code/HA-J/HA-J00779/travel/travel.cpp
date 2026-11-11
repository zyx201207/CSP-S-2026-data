#include<bits/stdc++.h>
using namespace std;
long long n,m,t;
string s,s1,s2,s3,s4,s5,s6,s7;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		cout<<1;
		for(int i=0;i<s1.size();i++){
			if(s1[i]>='0'&&s1[i]<='9')
				s4+=s1[i];
			else
				s6+=s1[i];
		}
		for(int i=0;i<s3.size();i++){
			if(s3[i]>='0'&&s3[i]<='9')
				s5+=s3[i];
			else
				s7+=s3[i];
		}
		if(s4==s5){
			cout<<1;
			if(s6=="F"&&s7=="D")
				cout<<1;
			else if(s6=="D"&&s7=="F")
				cout<<1;
			else if(s6=="A"&&s7=="B")
				cout<<1;
			else if(s6=="B"&&s7=="A")
				cout<<1;
			else if(s6=="A"&&s7=="C")
				cout<<1;
			else if(s6=="C"&&s7=="A")
				cout<<1;
			else if(s6=="B"&&s7=="C")
				cout<<1;
			else if(s6=="C"&&s7=="B")
				cout<<1;
			else
				cout<<"0";
			if(s6=="A"&&s7=="B")
				cout<<1;
			else if(s6=="B"&&s7=="A")
				cout<<1;
			else if(s6=="B"&&s7=="C")
				cout<<1;
			else if(s6=="C"&&s7=="B")
				cout<<1;
			else if(s6=="D"&&s7=="F")
				cout<<1;
			else if(s6=="F"&&s7=="D")
				cout<<1;
			else
				cout<<"0";
		}
		else
			cout<<"000";
		
	}
	else
		cout<<"0000";
	return 0;
}
