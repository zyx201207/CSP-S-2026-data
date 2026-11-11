#include<bits/stdc++.h>
using namespace std;
string s1;
string s2;
string s3;
string s4;
int n = 0,m = 0,b = 0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>s1>>s2>>s3>>s4;
	if(s1[1]==s3[1]&&s1[0]==s3[0]){
		cout<<1;
		b = 1;
	} 
	else cout<<0;

	if(s2[0] == s4[0]&&s2[1] == s4[1]&&b==1){
		cout<<1;
		b = 2;	
	} 
	else cout<<0;

	if(s2[2]=='D' or s2[2]=='F')n = 1;
	if(s4[2]=='D' or s4[2]=='F')m = 1;
	
	if(n==m&&b == 2){
		cout<<1;
		b = 3;	
	} 
	else cout<<0;

	
	if((s2[2]-1==s4[2]&&b == 3) or (s2[2]+1==s4[2]&&b == 3)) cout<<1;
	else cout<<0;
	
	
	return 0;
} 
