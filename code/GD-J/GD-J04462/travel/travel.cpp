#include<bits/stdc++.h>
using namespace std;
string car1,car2;
int sit1,sit2;
char num1,num2;
int k[10]={1,1,1,2,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a1,a2,a3,a4;
	cin>>car1>>a1>>a2>>num1>>car2>>a3>>a4>>num2;
	if(car1!=car2){
		cout<<"0000";
		return 0;
	}else{
		cout<<'1';
	}
	sit1=(a1-'0')*10+(a2-'0');
	sit2=(a3-'0')*10+(a4-'0');
	if(sit1!=sit2){
		cout<<"000";
		return 0;
	}else{
		cout<<'1';
	}
	if(k[num1-'A']!=k[num2-'A']){
		cout<<"00";
		return 0;
	}else{
		cout<<'1';
	}
	if(max(num1-'A',num2-'A')-min(num1-'A',num2-'A')==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
} 
