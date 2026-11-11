#include<bits/stdc++.h>
using namespace std;
bool fl1,fl2,fl3,fl4;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){fl1=true;}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&fl1==true){fl2=true;}	
	if(fl1&&fl2&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E')){
		fl3=true;
	} 	
	if(fl1&&fl2&&fl3&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&(s1[2]-s2[2]==1||s1[2]-s2[2]==-1))||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'&&(s1[2]-s2[2]==1||s1[2]-s2[2]==-1))){
	    fl4=true;
	}	
	cout<<fl1<<fl2<<fl3<<fl4;    
	return 0;
} 
