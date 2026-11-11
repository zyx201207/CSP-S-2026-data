#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	c1.push_back(s2[0]);
	c1.push_back(s2[1]);
	c2.push_back(s4[0]);
	c2.push_back(s4[1]);
	if((s1=="17")||(s1=="01")||(s3=="01")||(s3=="01")){
		cout<<"0000";
		return 0;
	}
	if(s1==s3){
		cout<<1;
		if(c1==c2){
			cout<<1;
			if(((s2[2]<='C') && (s4[2]<='C')) || ((((s2[2]>='D') && (s2[2]<='F')) && ((s4[2]<='F') && (s4[2]>='D'))))){
				cout<<1;
				if(((s2[2]<='C') && (s4[2]<='C')) && abs(s2[2]-s4[2])==1) cout<<1;
				else if(((((s2[2]>='D') && (s2[2]<='F')) && ((s4[2]<='F') && (s4[2]>='D')))) && abs(s2[2]-s4[2])==2) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

