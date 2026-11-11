#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	for(char i='A';i<='C';i++){
		if(i==s1[2])f1=true;
		if(i==s2[2])f2=true;
	}
	if(f1==f2){
		cout<<1;
		if(abs(s1[2]-s2[2])==1)cout<<1;  
		else cout<<0;
	}
	else cout<<0<<0;
	
	return 0;
}

