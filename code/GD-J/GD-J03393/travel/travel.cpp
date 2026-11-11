#include<bits/stdc++.h>
using namespace std;
string car_f,car_s,number_f,number_s;
int car_f_n=0,car_s_n=0;
int number_f_n=0,number_s_n=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>car_f>>number_f>>car_s>>number_s;
	if(car_f[0]=='0') car_f_n=car_f[1]-'0';
	else car_f_n=10+(car_f[1]-'0');
	if(car_s[0]=='0') car_s_n=car_s[1]-'0';
	else car_s_n=10+(car_s[1]-'0');
	//printf("%d %d",car_f_n,car_s_n);
	if(car_f_n!=car_s_n){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(number_f[0]=='0') number_f_n=number_f[1]-'0';
	else number_f_n=10+(number_f[1]-'0');
	if(number_s[0]=='0') number_s_n=number_s[1]-'0';
	else number_s_n=10+(number_s[1]-'0');
	//printf("%d %d",number_f_n,number_s_n);
	if(number_f_n!=number_s_n){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((number_f[2]=='A'||number_f[2]=='B'||number_f[2]=='C')&&(number_s[2]=='D'||number_s[2]=='F')){
		cout<<"00";
		return 0;
	}
	if((number_s[2]=='A'||number_s[2]=='B'||number_s[2]=='C')&&(number_f[2]=='D'||number_f[2]=='F')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	char a=number_f[2],b=number_s[2];
	if(a=='A'){
		if(b!='B') cout<<0;
		else cout<<1;
	}
	if(a=='B'){
		if(b!='A'||b!='C') cout<<0;
		else cout<<1;
	}
	if(a=='C'){
		if(b!='B') cout<<0;
		else cout<<1;
	}
	if(a=='D'){
		if(b!='F') cout<<0;
		else cout<<1;
	}
	if(a=='F'){
		if(b!='D') cout<<0;
		else cout<<1;
	}
	return 0; 
} 
