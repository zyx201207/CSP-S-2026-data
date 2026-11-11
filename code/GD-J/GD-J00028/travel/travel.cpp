#include<bits/stdc++.h>
using namespace std;

string c1,c2,c3,c4;//³µÏáºÅ+×ùÎ»ºÅ 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c2[0]+c2[1]==c4[0]+c4[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	bool flag=true;
	if(c2[2]=="A"||c2[2]=="B"||c2[2]=="C"){
		if(c4[2]=="A"||c4[2]=="B"||c4[2]=="C"){
			cout<<1;
			flag=false;
		}
	}
	else if(c2[2]=="D"||c2[2]=="E"){
		if(c4[2]=="D"||c4[2]=="E"){
			cout<<1;
			flag=false;
		}
	}
	if(flag==true){
		cout<<0;
	}
	if(c2[2]+1==c4[2]||c2[2]-1==c4[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
