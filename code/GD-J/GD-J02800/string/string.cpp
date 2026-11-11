#include<bits/stdc++.h>
using namespace std;
string s="";
int n,c=0,z;
long long h;
char x;
int main(){
freopen("string.txt","r",stdin);
freopen("string.txt","w",stdout);	
cin>>n;
for(int i=1;i<=n;i++){
	cin>>h>>x;
	for(int j=0;j<h;j++)	s+=x;
}
if(s.size()%2!=0) z=s.size()/2+1;
else z=s.size()/2; 
cout<<s;
for(int i=0;i<z;i++){
	if(s[s.size()-1-i]!=s[i]) c++;
}
cout<<c;
	return 0;
}
