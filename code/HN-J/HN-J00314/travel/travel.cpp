#include<bits/stdc++.h>
using namespace std;
int a,b,f,fl,fla;
string s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	if(a==b){
		fla=1;
		cout<<"1";
	}
	else cout<<"0";
	if(fla==1 && (s[0]==t[0] && s[1]==t[1])){
		f=1;
		cout<<"1";
	}
	else cout<<"0";
	if(f==1 && (s[2]<='C' && t[2]<='C') || (s[2]>='D' && t[2]>='D')){
		fl=1;
		cout<<"1";
	}
	else cout<<"0";
	if(fl==1 && (abs(s[2]-t[2])==1)) cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
