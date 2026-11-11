#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int car1,car2;
int pai1,pai2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int ss1=1;
	for(int i=s1.size()-1;i>=0;i--){
		int ss=(s1[i]-'0')*ss1;
		car1+=ss;
		ss1*=10;
	}
	ss1=1;
	for(int i=s3.size()-1;i>=0;i--){
		int ss=(s3[i]-'0')*ss1;
		car2+=ss;
		ss1*=10;
	}
	if(car1!=car2){
		cout<<"0000"<<endl;
		return 0;
	}
	else cout<<1;
	char c1=s2[s2.size()-1];
	char c2=s4[s4.size()-1];
	ss1=1;
	for(int i=s2.size()-2;i>=0;i--){
		int ss=(s2[i]-'0')*ss1;
		pai1+=ss;
		ss1*=10;
	}
	ss1=1;
	for(int i=s4.size()-2;i>=0;i--){
		int ss=(s4[i]-'0')*ss1;
		pai2+=ss;
		ss1*=10;
	}
	if(pai2!=pai1){
		cout<<"000"<<endl;
		return 0;
	}
	else cout<<1;
	int f1=0,f2=0;
	if(c1=='A'||c1=='B'||c1=='C') f1=1;
	else f1=2;
	if(c2=='A'||c2=='B'||c2=='C') f2=1;
	else f2=2;
	if(f1!=f2){
		cout<<"00"<<endl;
		return 0;
	}
	else{
		cout<<1;
	}
	int cc1=int(c1),cc2=int(c2);
	if(c1=='C'&&c2=='D'){
		cout<<0<<endl;
		return 0;
	}
	if(c1=='D'&&c2=='C'){
		cout<<0<<endl;
		return 0;
	}
	if(abs(cc1-cc2)==1){
		cout<<1<<endl;
	}
	else cout<<0<<endl;
	//cout<<car1<<" "<<car2<<" "<<pai1<<" "<<pai2<<" "<<c1<<" "<<c2<<""<<cc1<<" "<<cc2<<endl;
	return 0;
}
