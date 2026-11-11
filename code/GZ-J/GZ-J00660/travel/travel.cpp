//GZ-J00660 兴义市弘毅中学 陈润泽 
#include<bits/stdc++.h>
using namespace std;
string x1,x2,r1,r2;
char l1,l2,k1,k2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2>>r1>>r2;
	if(x1==r1){
	}else{
		cout<<"0000";return 0;
	}
	k1=x2[1];
	k2=r2[1];
	if(k1!=k2){
		cout<<"1000";
		return 0;
	}
//	for(int i=0;i<3;i++){
//		s=s+(x2[i]-'0');
//		n=n+(r2[i]-'0');
//	}
	l1=x2[2];
	l2=r2[2];
	if((l1<='C'&&(l2<='C'&&l2!=l1))||((l1=='D'&&l2=='F')||(l1=='F'&&l2=='D'))){
	}else{
		cout<<"1100";return 0;
	}if((l1=='A'&&l2=='C')||(l1=='C'&&l2=='A')||(l1=='A'&&l2=='D')||(l1=='D'&&l2=='A')||(l1=='A'&&l2=='F')||(l1=='F'&&l2=='A')||(l1=='B'&&l2=='D')||(l1=='D'&&l2=='B')||(l1=='B'&&l2=='F')||(l1=='F'&&l2=='B')||(l1=='C'&&l2=='D')||(l1=='D'&&l2=='C'))
	{
		cout<<"1110";
		return 0;
	}else{
		cout<<"1111\n";
			return 0;
	}	
} 
//
