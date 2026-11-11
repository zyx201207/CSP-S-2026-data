#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	string line1;
	string line2;
	line1+=s1[0];
	line1+=s1[1];
	line2+=s2[0];
	line2+=s2[1];
	if(line1==line2) cout<<"1";
	else cout<<"0";

	
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
		cout<<"1";
	    char t1=s1[2];
	    char t2=s2[2];
	    if(abs(t1-t2)==1)  cout<<"1";
	    else cout<<"0";
	}
 	else cout<<"00"; 
	
} 
