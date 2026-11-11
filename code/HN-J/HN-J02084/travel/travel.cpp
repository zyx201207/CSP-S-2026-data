#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[1]!=s2[1]||s1[0]!=s2[0]){
		cout<<"1000";
		return 0;
	}
	char t1=s1[2],t2=s2[2];
	if('A'<=t1&t1<='C'&'A'<=t2&t2<='C'||('D'==t1|t1=='F')&('D'==t2|t2=='F')){
		cout<<"111";
	}else{
		cout<<"1100";
		return 0;
	}
	int q=0;
	if(t1=='A'&t2=='B'||t1=='B'&t2=='A')q=1;
	if(t1=='C'&t2=='B'||t1=='B'&t2=='C')q=1;
	if(t1=='D'&t2=='F'||t1=='F'&t2=='D')q=1;
	cout<<q;
	
	return 0;
} 
