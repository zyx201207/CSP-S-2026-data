#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n1,n2;
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	n1 = s1[0]*10+s1[1];
	n2 = s3[0]*10+s3[1];
	if(n1!=n2){
		cout<<"0000";
	}else{
		cout<<"1";
		n1 = s2[0]*10+s2[1];
		n2 = s4[0]*10+s4[1];
		if(n1!=n2){
			cout<<"000";
		}else{
			cout<<"1";
			int flag1 = 0;
			int flag2 = 0;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')flag1 = 1;
			if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')flag2 = 1;
			if(flag1!=flag2)cout<<"00";
			else{
				cout<<"1";
				if(abs(s2[2]-s4[2])!=1)cout<<"0";
				else cout<<"1";
			}
		}
	}
	
	return 0;
}
