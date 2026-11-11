#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("C:\\Users\\Administrator\\Desktop\\travel\\travel.in","r",stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\travel\\travel.out","w",stdout);
	string c1,s1,c2,s2;
	for(int i=0;i<2;i++){
		cin>>c1[i]>>c2[i]; 
	}
	for(int i=0;i<3;i++){
		cin>>s1[i]>>s2[i];
	}
	if(c1==c2){
		cout<<1;
	}
	if(c1!=c2){
		cout<<0;
	}
	int num=0;
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			num++;
		}
	}
	int count=0;
	if(num==2){
		cout<<1;
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
			cout<<1;
			count++;
		}
		if(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'){
			cout<<1;
			count++;
		}
		else{
			cout<<0;
		}
	}
	if(num!=2){
		cout<<0;
	}
	if(c1==c2&&num==2&&count!=0){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0; 
}
