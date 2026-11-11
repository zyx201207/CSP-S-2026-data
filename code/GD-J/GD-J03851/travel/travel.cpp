#include <bits/stdc++.h>
using namespace std;
int chexiang1,chexiang2;
bool flag=1; 
string seat1,seat2;
int row1,row2,col1,col2;//A 0 B 1 C 2 D 4 F 5
int main(){
	cin>>chexiang1>>seat1>>chexiang2>>seat2;
	if(chexiang1==chexiang2){
		cout<<'1';
	}else{
		cout<<'0';
		flag=0;
	}
	row1=(seat1[0]-'0')*10+seat1[1]-'0';
	col1=seat1[2]-'A';
	if(seat1[2]=='D')col1++;
	row2=(seat2[0]-'0')*10+seat2[1]-'0';
	col2=seat2[2]-'A';
	if(seat2[2]=='D')col2++;
	if(flag&&(row1==row2)){
		cout<<'1';
	}else{
		cout<<'0';
		flag=0;
	}
	if(flag&&((col1<3&&col2<3)||(col1>3&&col2>3))){
		cout<<'1';
	}else{
		cout<<'0';
		flag=0;
	}
	if(flag&&((col1-col2==1)||(col2-col1==1))){
		cout<<'1';
	}else{
		cout<<'0';
		flag=0;
	}
	return 0;
	
}
