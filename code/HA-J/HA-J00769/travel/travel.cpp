#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	p1=s1[0]+s1[1];
	p2=s2[0]+s2[1];
	if(p1==p2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	p1=s1[2];
	p2=s2[2];
	if((p1=="D"||p1=="F")&&(p2=="D"||p2=="F")){
		cout<<"11";
		return 0;
	}if((p1=="A"||p1=="B"||p1=="C")&&(p2=="A"||p2=="B"||p2=="C")){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((p1=="A"&&p2=="B")||(p1=="B"&&p2=="C")){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
