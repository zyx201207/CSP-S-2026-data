#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		int id1=(s1[0]-48)*10+s1[1]-48;
		int id2=(s2[0]-48)*10+s2[1]-48;
		char t1=s1[2],t2=s2[2];
		if(id1==id2){
			if(((t1=='A'||t1=='B'||t1=='C')&&(t2=='A'||t2=='B'||t2=='C'))||((t1=='D'||t1=='F')&&(t2=='D'||t2=='F'))) cout<<"111";
			else cout<<"110";
		}
		else cout<<"100";
		if((id1==id2)&&((t1-t2==1)||(t1-t2==-1))){
			if((t1=='D'||t1=='F')&&(t2=='A'||t2=='B'||t2=='C')) cout<<0;
			else if((t2=='D'||t2=='F')&&(t1=='A'||t1=='B'||t1=='C')) cout<<0;
			else cout<<1;
		}
		else if((t1==t2)&&((id1-id2==1)||(id1-id2==-1))) cout<<1;
		else cout<<"0";
	}
	else cout<<"0000";
	return 0;
}