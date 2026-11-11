#include<bits/stdc++.h>
using namespace std;
int nu,k;
char c;
string s="",s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>nu>>c;
		for(int j=1;j<=nu;j++){s+=c;}}
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2;i++){s1+=s[i];}
		string st=s1;
		reverse(s1.begin(),s1.end());
		s1=st+s1;
		for(int i=0;i<s.size();i++){
            if(s1[i]!=s[i]){k++;}}}
    else{
        for(int i=1;i<=s.size()/2;i++){
            if(s[s.size()/2-i]!=s[s.size()/2+i]){k++;}}}
    cout<<k;}
