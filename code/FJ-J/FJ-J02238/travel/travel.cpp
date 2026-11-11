#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int check1(){
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			return 0;
		}
	} 
	return 1;
}
int check2(){
	if(check1()==1){
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				return 0;
			}
		} 
		return 1;
	}
	return 0;
}
int check3(){
	if(check2()==1){
		if(s1[2]=='D'||s1[2]=='F'){
			if(s2[2]=='D'||s2[2]=='F')return 1;
			else return 0;
		}
		else if((s2[2]!='D'&&s2[2]!='F')){
			return 1;
		}
		else return 0;
	}
	return 0;
}
int check4(){
	if(check3()==1){
		if(s1[2]=='D'||s1[2]=='F'){
			return 1;
		}
		else if(abs(s1[2]-s2[2])==1)
			return 1;
		return 0;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<check1()<<check2()<<check3()<<check4();
} 
