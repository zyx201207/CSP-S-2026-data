#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string sub={"ABCDE"};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int num1,num2,c,d,flag=0;
	char ch,ch1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0' && s1[i]<='9'){
			num1=s1[i]-'0';
		}else{
			ch=s1[i];
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0' && s2[i]<='9'){
			num2=s2[i]-'0';
		}else{
			ch1=s2[i];
		}
	}
	c=sub.find(ch);
	d=sub.find(ch1);
	if(c<=2 && d<=2 || c>=3 && d>=3){
		flag=1;
	}
//	cout<<c<<" "<<d<<endl; 
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2 && num1==num2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2 && num1==num2 && flag){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2 && num1==num2 && flag && abs(c-d)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return  0;
}
