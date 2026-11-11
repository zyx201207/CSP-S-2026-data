#include<bits/stdc++.h>
using namespace std;

struct tr{
	string trainid;//³µÏáºÅ 
	string seatid;//×ùÎ»ºÅ 
}r,x;
bool ist(string t1,string t2){//is same train
	if(t1==t2) return true;
	else return false;
}
bool isl(string s1,string s2){//is same line
	if(s1[0]==s2[0]){
		if(s1[1]==s2[1]) return true;
		else return false;
	}else return false;
}
bool iss(string s1,string s2){//is same seat
	char ss1=s1[2],ss2=s2[2];
	if(ss1<='C'&&ss1>='A'){
		if(ss2<='C'&&ss2>='A') return true;
		else return false; 
	}else if(ss1<='D'&&ss1>='F'){
		if(ss2<='D'&&ss2>='F') return true;
		else return false;
	}
}
bool inteo(string s1,string s2){//is next to each other
	char ss1=s1[2],ss2=s2[2];
	if(abs(ss1-ss2)==1) return true;
	else return false;
}

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r.trainid >>r.seatid >>x.trainid >>x.seatid ;
	if(!ist(r.trainid ,x.trainid )){
		cout<<"0000";
		return 0;
	}
	if(!isl(r.seatid ,x.seatid )){
		cout<<"1000";
		return 0;
	}
	if(!iss(r.seatid ,x.seatid )){
		cout<<"1100";
		return 0;
	}
	if(!inteo(r.seatid ,x.seatid )){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	
	return 0;
} 
