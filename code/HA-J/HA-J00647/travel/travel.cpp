#include<bits/stdc++.h>
using namespace std;
string s1,s2,pos1,pos2,st1,st2;
int seat1,seat2;
bool check(int a,int b){
	if((a>=4&&a<=5&&b>=4&&b<=5)||(a>=1&&a<=3&&b>=1&&b<=3)){
		return 1;
	}
	return 0;
}
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>s1>>st1>>s2>>st2;
	if(s1!=s2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}//同一车厢 
	pos1+=st1[0];
	pos1+=st1[1];
	pos2+=st2[0];
	pos2+=st2[1];
	seat1=st1[2]-'A'+1;
	seat2=st2[2]-'A'+1;
//	cout<<st1<<' '<<st2<<' '<<pos1<<' '<<pos2<<" "<<seat1<<' '<<seat2<<endl; 
	if(pos1!=pos2){
		cout<<"000";
		return 0;
	}
	else{
		cout<<1;
	}//同一排 
	if(check(seat1,seat2)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}//同一侧
	if(abs(seat1-seat2)==1){
		cout<<1;
	} 
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
