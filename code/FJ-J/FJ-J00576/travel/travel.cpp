#include<bits/stdc++.h>
using namespace std;
string R_che,X_che;
string R_pai,X_pai;
string ok="0000";
char check1(char a,char b){
	int x=a-'A',y=b-'A';
	if(x<=2&&y<=2&&x>=0&&y>=0) {
	return '1';}
	if(x>=3&&y>=3) {
	return '1';}
	return '0'; 
}
char check(char a,char b){
	int x=a-'A',y=b-'A'; //A:0 B:1 C:2  D:3 F=5;
	if(x>y) swap(x,y); //x<y;
	if(x==y){return '0';}
	if(x==0&&y==1){return '1';}
	if(x==1&&y==2){return '1';}
	if(x==3&&y==5){return '1';}
	return '0';
}
signed main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>R_che>>R_pai;
cin>>X_che>>X_pai;
//cout<<R_che<<" "<<R_pai<<"\n";
//cout<<X_che<<" "<<X_pai;
if(R_che==X_che){ //同一车 
	ok[0]='1';
	if((R_pai[0]==X_pai[0])&&(R_pai[1]==X_pai[1])){ //同一排 
//	cout<<R_pai[0]<<" "<<" "<<X_pai[0]<<" "<<R_pai[1]<<" "<<X_pai[1]<<"\n";
		ok[1]='1';    
		ok[2]=check1(R_pai[2],X_pai[2]); //同一侧 
		if(ok[2]=='1'){
			ok[3]=check(R_pai[2],X_pai[2]);
		}
	}
}
cout<<ok;
cout<<endl; 
return 0;
}

