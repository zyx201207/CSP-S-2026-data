#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";	
		return 0;
	}
	if(s1[0]+s1[1]==s2[0]+s2[1]){
		cout<<"1";	
	}else{
		cout<<"000";
		return 0;	
	}
	int a=s1[2]-'A'+1;
	int b=s2[2]-'A'+1;
	if((a<=3&&b<=3)||(a>=4&&b>=4)){
		cout<<"1";
	} else{
		cout<<"00";	
		return 0;
	}
	if(a<=3){
		if((a==1&&b==3)||(a==3&&b==1)){
			cout<<"0";
		}else{
			cout<<"1";
		}
	} else {
		cout<<"1";
	}
	return 0;
}
