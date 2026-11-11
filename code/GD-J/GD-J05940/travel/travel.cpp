#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string x1,y1,x2,y2;
int check(string n,string m){
	if(n=="A"&&m=="B" || n=="B"&&m=="A"){
		cout<<"11";
		return 0;
	}
	if(n=="A"&&m=="C" || n=="C"&&m=="A"){
		cout<<"10";
		return 0;
	}
	if(n=="C"&&m=="B" || n=="B"&&m=="C"){
		cout<<"11";
		return 0;
	}
	if(n=="D"&&m=="F" || n=="F"&&m=="D"){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	x1+=s1[0];
	x1+=s1[1];
	y1=s1[2];
	x2+=s2[0];
	x2+=s2[1];
	y2=s2[2];
	if(x1==x2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	check(y1,y2);
	return 0;
} 
