#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int R1,R2,R3,X1,X2,X3;
    R1=(c1[0]-'0')*10+c1[1]-'0';
    X1=(c2[0]-'0')*10+c2[1]-'0';
    if(R1!=X1){
    	cout<<"0000";
    	return 0;
	}
	cout<<1;
	R2=(s1[0]-'0')*10+s1[1]-'0';
    X2=(s2[0]-'0')*10+s2[1]-'0';
    if(R2!=X2){
    	cout<<"000";
    	return 0;
	}
	cout<<1;
	R3=s1[2]-'A'+1;
	X3=s2[2]-'A'+1;
	if((R3==4||R3==5)){
		if(X3==4||X3==5) cout<<"11";
		else cout<<"00";
	}else if(X3==4||X3==5) cout<<"00";
	else if((R3==1&&X3==2)||(R3==2&&X3==1)||(R3==3&&X3==2)||(R3==2&&X3==3)){
		cout<<"11";
	}else cout<<"10"; 
	return 0;
}
