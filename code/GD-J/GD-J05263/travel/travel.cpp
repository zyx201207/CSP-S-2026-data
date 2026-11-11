#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,b1;
int as1,as2,as3,as4;
int cas3(char s1,char s2){
	if(s1==s2)return 1;
	if(s1>='A'&&s1<='C'){
		if(s2>='A'&&s2<='C'){
			return 1;
		}
	}else if(s1>='D'&&s1<='F'){
		if(s2>='D'&&s2<='F'){
			return 1;
		}	
	}
	return 0;
}
int cas4(char d1,char d2){
	if(as3==1){
		if(d1==d2+1||d2==d1+1)return 1;
	}
	if(d1=='D'||d1=='F'){
		if(d2=='D'||d2=='F')return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	as1=0;//两张车票对应的座位是否在同一节车厢
	as2=0;//两张车票对应的座位是否在同一节车厢的同一排 
	as3=0;//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
	as4=0;//两张车票对应的座位是否相邻
	cin>>a>>a1>>b>>b1;
	if(a==b){
		as1=1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a1[0]==b1[0]){
		if(a1[1]==b1[1]){
			as2=1;
			as3=cas3(a1[2],b1[2]);
		}
	}
	as4=cas4(a1[2],b1[2]);
	cout<<as1<<as2<<as3<<as4;
	return 0;
}
