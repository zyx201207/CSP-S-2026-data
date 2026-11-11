#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a="ABC";
bool check1(){
	if(s1[0]==s2[0] and s1[1]==s2[1]){
		return true;
	}
	return false;
}
bool check2(){
	char side1=s1[2],side2=s2[2];
	int x=2,y=2;
	for(int i=0;i<3;i++){
		if(side1==a[i]) x=1;
		if(side2==a[i]) y=1;
	}
	return x==y;
}
bool check3(){
	char seat1=s1[2],seat2=s2[2];
	if((seat1=='A' and seat2=='F') or (seat1=='F' and seat2=='A')){
		return false;
	}
	return seat1+1==seat2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	//prob1
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";return 0;
	}
	//porb2
	if(c1==c2 and check1()){
		cout<<1;
	}else{
		cout<<"000";return 0;
	}
	//porb3
	if(c1==c2 and check1() and check2()){
		cout<<1;
	}else{
		cout<<"00";return 0;
	}
	//prob4
	if(check3()){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
