 //GZ-J00513 兴义市弘毅中学 李宇轩 
 #include<bits/stdc++.h>
using namespace std;
char n1[5],n2[5];
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1[0]>>n1[1]>>n1[2]>>n1[3]>>n1[4];
	cin>>n2[0]>>n2[1]>>n2[2]>>n2[3]>>n2[4];
	if(n1[1]==n2[1]&&n2[0]==n2[0])cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(n1[3]==n2[3]&&n1[2]==n2[2])cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	if((n1[4]=='C'&&n2[4]=='D')||(n2[4]=='C'&&n1[4]=='D')){
	cout<<"00";
	return 0;
	}
	
	if(n1[4]-'A'+n2[4]-'A'<4||n1[4]-'A'+n2[4]-'A'==8)cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if((n1[4]=='F'&&n2[4]=='D')||(n2[4]=='F'&&n1[4]=='D')){
	cout<<"1";	
	return 0;	
	}
	if(n1[4]-'A'==n2[4]-'A'+1||n1[4]-'A'==n2[4]-'A'-1)cout<<"1";
	else cout<<"0";
	
	return 0;
}
