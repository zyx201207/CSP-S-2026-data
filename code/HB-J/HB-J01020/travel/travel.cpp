#include<bits/stdc++.h>
using namespace std;
int f1=0,f2=0,f3=1,f4=1;
char c1[5],s1[5],s2[5],c2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++)cin>>c1[i];
	for(int i=0;i<3;i++)cin>>s1[i];
	for(int i=0;i<2;i++)cin>>c2[i];
	for(int i=0;i<3;i++)cin>>s2[i];
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			f1=1;
			break;
		}
	}
	if(f1==1){
		for(int i=1;i<=4;i++){
			cout<<"0";
		}
		
	}
	else{
		cout<<"1";
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				f2=1;break;
			}
		}
		if(f2==1){
			for(int i=1;i<=3;i++){
			cout<<"0";
			}
		}
	else{
		cout<<"1";
		if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C' and s2[2]!='D' and s2[2]!='E'){
			f3=0;
			cout<<"1";
		}
		if(s1[2]=='D' and s2[2]=='E'){
			f3=0,f4=0;
			cout<<"1";
		}
		if(s1[2]=='E' and s2[2]=='D'){
			f3=0,f4=0;
			cout<<"1";
		}
		if(f3==1){
			for(int i=1;i<=2;i++){
				cout<<"0";
			}
		}
		else{
			if(s1[2]=='A' and s2[2]=='B'){
				f4=0;
				cout<<"1";
			}
			if(s1[2]=='B' and s2[2]=='C' or s2[2]=='A'){
				f4=0;
				cout<<"1";
			}
			if(s1[2]=='C' and s2[2]=='B'){
				f4=0;
				cout<<"1";
			}
			if(f4==1){
				cout<<"1";
			}
		}
	}
}
	return 0;
}
