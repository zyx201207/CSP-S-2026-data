#include<bits/stdc++.h>
using namespace std;
//HN-J02304
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)	cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}  
	if(s1[1]==s2[1])	cout<<"1";  
	else{
		cout<<"000";
		return 0;
	}	
	if(s1[2]<=3||s2[2]<=3 && 3<s1[2]<=5||3<s2[2]<=5)	cout<<"1";  
	else{
		cout<<"00";
		return 0;
	}	
	if(s1[1]==s2[1])	cout<<"1"; 
	else	cout<<"0";
	return 0;
}
