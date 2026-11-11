#include<bits/stdc++.h>
using namespace std;
char c1,c2,b1,b2,d1=0,d2=0;
string s1;
string s2;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	for(int j=0;j<s1.size();j++){
		if(s1[j]<='9'&&s1[j]>='0')b1+=s1[j];
		else d1+=s1[j];
	}
	for(int i=0;i<=s2.size();i++){
		if(s2[i]<='9'&&s2[i]>='0')b2+=s2[i];
		else d2+=s2[i];
	}
	if(c1=c2){	
	cout<<"1";
	if(b1==b2){
	cout<<"1";
	if(d1>='A'&&d1<='C' && d2>='A'&&d2<='C'  ||  d1>='D'&&d1<='F' && d2>='D'&&d2<='F')cout<<"1";
	else cout<<"0";
	if(d1-1==d2 || d2-1==d1)cout<<"1";
	else cout<<"0";
	}
	else cout<<"0";
	}
	else cout<<"0";
	return 0;
}
