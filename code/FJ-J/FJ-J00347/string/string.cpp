#include <bits/stdc++.h>
using namespace std;
int n,m1,m2;
string s1,s2,s3;
int main(){
	froepen("string.in","r",stdin);
	froepen("string.out","w",stdout);
	cin>>n;
	if(n==1)cout<<0;
	if(n==2){
		cin>>m1>>s1>>m2>>s2;
		if((m1==m2)||(s1==s2))cout<<0;
		else cout<<1;
	}

}
