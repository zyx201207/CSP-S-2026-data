#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);	
int e;
long long b,z=0;
long long d=0;
cin>>e;
string s[e+1];
for(int i=0;i<e;i++){
	cin>>b>>s[i];
	if(s[0]!=s[i]&&s[i]==s[i-1]){
	d=d+b;
	}
	if(i>0)	z+=b;
}
if(e%2==0){
cout<<d;
}else{
cout<<z/2;
}
return 0;
}
