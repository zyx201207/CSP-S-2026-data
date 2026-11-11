#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c2,s2,c3,s3;
	cin>>c2>>s2>>c3>>s3;
	if(c2==c3)
		cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]+s2[1]==s3[0]+s3[1])
		cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if(s2[2]>='A'&&s2[2]<='C'&&s3[2]>='A'&&s3[2]<='C'||s2[2]>='D'&&s2[2]<='F'&&s3[2]>='D'&&s3[2]<='F'){
		cout<<'1';
		if(abs(int(s3[2]-s2[2]))==1) 
			cout<<'1';
		else
			cout<<'0';
	}
	else
		cout<<"00";
	return 0;
} 
