#include<bits/stdc++.h>
using namespace std;
/*
同一车厢
同一排
同一侧
相邻

*/
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//输入
	cin>>c1>>c2>>c3>>c4;
	//同一车厢
	if(c1==c3){
		cout<<"1";
	}else{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	//同一排
	string pai1=c2.substr(0,2);
	//cout<<pai1;
	string pai2=c4.substr(0,2);
	if(pai1==pai2){
		cout<<"1";
	}else{
		cout<<"0"<<"0"<<"0";
		return 0;
	}
	char no1=c2[2];
	char no2=c4[2];
//	cout<<endl<<c2[2]<<" "<<c4[2];
	//同一侧
	if(no1=='A'||no1=='B'||no1=='C'){
		if(no2=='A'||no2=='B'||no2=='C'){
			cout<<"1";
			//相邻
			if((no1=='A'&&no2=='B')||(no1=='B'&&no2=='A')||(no1=='B'&&no2=='C')||(no1=='C'&&no2=='B')){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0"<<"0";
		}
	}else if(no1=='D'||no1=='F'){
		if(no2=='D'||no2=='F'){
			cout<<"1"<<"1";
			//
		}else{
			cout<<"0"<<"0";
		}
	}
	return 0;
}
