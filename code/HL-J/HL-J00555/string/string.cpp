#include<bits/stdc++.h>
using namespace std;
struct S{
	int a;
	string b;};
S s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>s[i].a>>s[i].b;
	long long i=0,j=n-1,ans=0;
	while(i<j){
		if(s[i].b==s[j].b){
			if(s[i].a==s[j].a){
				s[i].a=0;
				s[j].a=0;}
			else if(s[i].a>s[j].a){
				s[i].a-=s[j].a;
				s[j].a=0;}
			else {
				s[j].a-=s[i].a;
				s[i].a=0;}}
		else{
			if(s[i].a>=s[j].a){
				s[j].b=s[i].b;
				ans+=s[j].a;}
			else if(s[i].a<s[j].a){
				s[i].b=s[j].b;
				ans+=s[i].a;}}
		if(s[i].a==0)i++;
		if(s[j].a==0)j--;}
	cout<<ans;
	return 0;}
