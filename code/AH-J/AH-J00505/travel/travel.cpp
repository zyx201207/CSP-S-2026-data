#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	int n1,n2,n3,n4;
	int i=0;
	cin>>c1>>s1>>c2>>s2;
	
	if((s1[0]==s2[0] && s1[1]==s2[1]) && s1[2]+'1'==s2[2]){
		if(s2[2]+'1'=='D'){
			n1=0;
			n3=0;
		}
		n1=1;
		n3=1;
	}
	if(c1==c2){
		n2=1;
		n4=1;
	}else{
		n2=n4=0;
	} 
		

	cout<<n1<<n2<<n3<<n4;
	return 0;	
}
