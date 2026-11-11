#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	
	int c1,c2;
	string s1;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	 
	if(c1==c2)
		cout<<"1";
	else{
		cout<<"0000"<<endl;
		return 0;
    } 
	if( (s1[0]-'0'==s2[0]-'0') && (s1[1]-'0'==s2[1]-'0') )
		cout<<"1";
	else{
		cout<<"000"<<endl;
		return 0;
	}
	if( (s1[2]-'A'<3 && s2[2]-'A'<3 && s1[2]-'A'>=0 && s2[2]-'A'>=0) || (s1[2]-'D'<3 && s2[2]-'D'<3 && s1[2]-'D'>=0 && s2[2]-'D'>=0) )
	    cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(s1[2]-'A'<3 && s2[2]-'A'<3){
		if(abs((s1[2]-'0') - (s2[2]-'0'))==1)
		    cout<<"1";
		else
		    cout<<"0"<<endl;
		    return 0;
	}
	else if(s1[2]-'D'<3 && s2[2]-'D'<3){
		if(abs((s1[2]-'0') - (s2[2]-'0'))==2)
		    cout<<"1";
		else
		    cout<<"0"<<endl;
		    return 0;
	}
	else
	    cout<<"0"<<endl;
	return 0;
}





