#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,a,b;
	bool c=false,d=false;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	a=s1[2];
	b=s2[2];
	if(a>=65&&a<=67)c=true;
	if(b>=65&&b<=67)d=true;
	if(a>b){
		n=a-b;
	}else n=b-a;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2&&c==d){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2&&c==d&&n==1){
		cout<<1;
	}else cout<<0;
	return 0;
}
