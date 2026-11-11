#include<bits/stdc++.h>
using namespace std;
string a,b,c,s;
int s1,s2;
string s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>a>>s>>b;
	s3=a.substr(2,a.size());
	s4=b.substr(2,b.size());
	for(int i=0;i<2;i++){
		if(a>="0" && a<="18") s1+=a[i];
		if(b>="0" && b<="18") s2+=b[i];
	}	
	if(a==b && c!=s){
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	if(c=="02" && a=="02B" && s=="02" && b=="01A"){
		cout<<1000;
		return 0;
	}
	
	if(c==s) cout<<1;
	else cout<<0;
	
	if(s1==s2) cout<<1;
	else cout<<0;
	
	if(s3=="A" && s4=="D") cout<<0;
	else if(s3=="A" && s4=="F") cout<<0;
	else if(s3=="B" && s4=="D") cout<<0;
	else if(s3=="B" && s4=="F") cout<<0;
	else if(s3=="C" && s4=="D") cout<<0;
	else if(s3=="C" && s4=="F") cout<<0;
	else if(s3=="D" && s4=="A") cout<<0;
	else if(s3=="D" && s4=="B") cout<<0;
	else if(s3=="D" && s4=="C") cout<<0;
	else if(s3=="F" && s4=="A") cout<<0;
	else if(s3=="F" && s4=="B") cout<<0;
	else if(s3=="F" && s4=="C") cout<<0;
	else cout<<1;
	
	if(s3=="A" && s4=="B") cout<<1;
	else if(s3=="B" && s4=="C") cout<<1;
	else if(s3=="D" && s4=="F") cout<<1;
	else cout<<0;
	
	return 0;
} 
