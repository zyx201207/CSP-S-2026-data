#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int n1=(c1[0]-'0')*10+(c1[1]-'0');
	int n2=(c2[0]-'0')*10+(c2[1]-'0');
	if(n1==n2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	n1=(s1[0]-'0')*10+(s1[1]-'0');
	n2=(s2[0]-'0')*10+(s2[1]-'0');
	if(n1==n2){
		cout<<"1";
		int m1=(s1[2]-'A'+1);
		int m2=(s2[2]-'A'+1);
		if((m1<=3&&m2>3)||(m1>3&&m2<=3)){
			cout<<"00";
		}else{
			cout<<"1";
			if(abs(m2-m1)==1){
				cout<<"1";
			}else{
				cout<<"0"; 
			}
		}
	}else{
		cout<<"000";
	}
	return 0;
} 
