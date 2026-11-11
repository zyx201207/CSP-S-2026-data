#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flg=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char x=s1[2],y=s2[2];
	//1
	if(c1==c2){
//		cout<<"1yi"<<endl;//
		cout<<1;
	}
	else{
//		cout<<"0yi"<<endl;//
		flg=0;
		cout<<0;
	}
//	cout<<endl;//
	//2
	if(flg==1 && s1[0]==s2[0] && s1[1]==s2[1] && s1[2]!=s2[2]){
//		cout<<"1er"<<endl;//
		cout<<1;
	}
	else{
//		cout<<"0er2"<<endl;//
		flg=0;
		cout<<0;	
	}
//	cout<<endl;//
	//3
	if(flg && x>='A' && x<='C' && y>='A' && y<='C'){
//		cout<<"1san1"<<endl;//
		cout<<1;
	}
	else if(flg && x>='D' && x<='F' && y>='D' && y<='F'){
//		cout<<"1san2"<<endl;//
		cout<<1;
	}
	else{
//		cout<<"0san"<<endl;//
		flg=0;
		cout<<0;
	}
//	cout<<endl;//
	//4
	if(flg){
		if((x=='A' && y=='B') || (x=='B' && y=='A') || (x=='B' && y=='C') || (x=='C' && y=='B') || (x=='D' && y=='F') || (x=='F' && y=='D')){
//			cout<<"1si"<<endl;//
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
//		cout<<"0si"<<endl;//
		cout<<0;
	}
	//
	return 0;
}
