#include<bits/stdc++.h>
using namespace std;
/*
两张车票对应的座位是否在同一节车厢；
两张车票对应的座位是否在同一节车厢的同一排；
两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
两张车票对应的座位是否相邻
*/
string c1,c2,s1,s2,f,z1,z2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	z1=s1[0]+s1[1];
	z2=s2[0]+s2[1];
	if(z1!=z2){
		cout<<"1000";
		return 0;
	}
	if(!((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'))){
		cout<<"1100";
		return 0;
	}
	if(!(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A'))||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
