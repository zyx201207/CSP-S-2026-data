#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
string num1,num2,num3,num4;
bool check(string a,string b){
	char ch1=a[2],ch2=b[2];
	if(ch2<ch1){
		swap(ch1,ch2);
	}
	if(ch1=='A'&&ch2=='B'){
		return true;
	}
	if(ch1=='B'&&ch2=='C'){
		return true;
	}
	if(ch1=='D'&&ch2=='F'){
		return true;
	}
	if(ch1=='A'&&ch2=='C'){
		return true;
	}
	return false;
}
bool cal(string a,string b){
	char ch1=a[2],ch2=b[2];
	if(ch2<ch1){
		swap(ch1,ch2);
	}
	if(ch1=='A'&&ch2=='C'){
		return true;
	} 
	else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>num1>>num2>>num3>>num4;
	bool flag1,flag2,flag3,flag4;
	if(num1==num3){
		flag1=true;
	}
	else{
		flag1=false;
	}
	string cur1="",cur2="";
	for(int i=0;i<2;++i){
		cur1+=num2[i];
		cur2+=num4[i];
	}
	if(flag1&&cur1==cur2){
		flag2=true;
	}
	else{
		flag2=false;
	}
	bool ans1=check(num2,num4);
	if(flag2&&ans1){
		flag3=true;
	}
	else{
		flag3=false;
	}
	bool ans2=cal(num2,num4);
	if(flag1&&flag2&&flag3&&!ans2){
		flag4=true;
	}
	else{
		flag4=false;
	}
	string anss="";
	if(flag1){
		anss+='1';
	}
	else{
		anss+='0';
	}
	if(flag2){
		anss+='1';
	}
	else{
		anss+='0';
	}
	if(flag3){
		anss+='1';
	}
	else{
		anss+='0';
	}if(flag4){
		anss+='1';
	}
	else{
		anss+='0';
	}
	cout<<anss;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
