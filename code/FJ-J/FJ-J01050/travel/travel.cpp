#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
char con[7]={0,'A','B','C','X','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string st1,se1,st2,se2;
	cin>>st1>>se1>>st2>>se2;
	if(st1=="01"||st1=="16"||st2=="01"||st2=="16"){
		cout<<"0000"<<endl;
		exit(0);
	}
	if(st1!=st2){
		cout<<"0000"<<endl;
		exit(0);
	}
	cout<<1;
	if(se1[0]!=se2[0]||se1[1]!=se2[1]){
		cout<<"000"<<endl;
		exit(0);
	}
	cout<<1;
	int loc1,loc2;
	for(int i=1;i<=6;i++){
		if(se1[2]==con[i]){
			loc1=i;
		}
		if(se2[2]==con[i]){
			loc2=i;
		}
	}
	int loc3=max(loc1,loc2),loc4=min(loc1,loc2);
	for(int i=loc4;i<=loc3;i++){
		if(con[i]=='X'){
			cout<<"00"<<endl;
			exit(0);
		}
	}
	cout<<1;
	if(loc3-loc4==1){
		cout<<1;
		exit(0);
	}
	cout<<0;
	return 0;
}
