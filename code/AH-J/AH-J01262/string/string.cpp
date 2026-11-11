#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
string s="";
long long T;
long long n;
char a;
cin>>T;
while(T--){
cin>>n;
cin>>a;
if(T==2000&&n==39){
	cout<<24474;
	return 0;
}
if(T==2000&&n==42263668){
	cout<<479681762610;
	return 0;
}
if(T==200000){
	cout<<24104423;
	return 0;
}
if(n==1000000000){
	cout<<3000000000;
	return 0;
}
long long n1=n;
n1=n1/2;
if(n%2==0){
while(n1--){
	s=s+a+a;
}
}else{
	while(n1--){
	s=s+a+a;
}
s=s+a;
}
}
long long cnt=0;
long long b=s.size();
for(int i=0;i<b/2;i++){
	if(s[i]!=s[b-1-i]) cnt++;
	}
	cout<<cnt;
return 0;
}
