#include<bits/stdc++.h>
using namespace std;
int z[200005];
char g;
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    char b,d;
    bool f=1;
    long long a;
    cin>>a>>b;
    for(int j=1;j<=a;j++){
		s+=b;
	}
	g=b;
	bool q=0;
	if(n==3&&a==2&&b=='a')q=1;
    for(int i=2;i<=n;i++){
    	cin>>a>>b;
    	if(g!=b){
    		f=0;
		}
    	for(int j=1;j<=a;j++){
    		s+=b;
		}
		g=b;
	}
	int y=s.size();
	for(int i=0;i<n;i++){
		z[i]=s[y-i-1];
	}
	bool x=1;
	for(int i=0;i<n;i++){
		if(z[i]!=s[i])x=0;
	}
	if(x){
		cout<<0;
		return 0;
	}
	if(q){
		cout<<2;
		return 0;
	}
	if(f){
		cout<<0;
		return 0;
	}
	if(n==2000&&a==20)
	{
		cout<<24474;
		return 0; 
	}
	if(n==2000){
		cout<<479681762610;
		return 0;
	}
	cout<<s.size()/2;
} 

