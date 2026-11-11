#include<bits/stdc++.h>
using namespace std;
long long c1,c2,t=1;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		t=0;
	}
	if (s1[0]==s2[0] && s1[1]==s2[1] && t==1){
		cout<<1;
	}
	else{
		cout<<0;
		t=0;
	}
	if ((s1[2]-'A'<=2 && s2[2]-'A'<=2 && t==1)||(s1[2]-'A'>2 && s2[2]-'A'>2&& t==1)){
		cout<<1;
	}
	else{
		cout<<0;
		t=0;
	}
	if(abs(s1[2]-s2[2])==1 && t==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
