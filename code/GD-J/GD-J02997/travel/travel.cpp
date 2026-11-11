#include<bits/stdc++.h>
using namespace std;
string C1,S1,C2,S2,COUT="0000";
int car_index1,car_index2,p1,p2;
int f1,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1>>S1>>C2>>S2;
	//判断是否同车厢 
	for(int i=0;i<2;i++){
		car_index1=car_index1*10+(C1[i]-'0');
		car_index2=car_index2*10+(C2[i]-'0');
	}
	if(car_index1!=car_index2){
		COUT="0000";
		cout<<COUT;
		return 0;
	}
	//判断是否同一排 
	for(int i=0;i<2;i++){
		p1=car_index1*10+(S1[i]-'0');
		p2=car_index2*10+(S2[i]-'0');
	}
	if(p1!=p2){
		COUT="1000";
		cout<<COUT;
		return 0;
	}
	//判断是否同一侧
	f1=S1[2]-'A';
	f2=S2[2]-'A';
	if(!( ((f1>=0 && f1<=2)&&(f2>=0 && f2<=1)) || ((f1==3||f1==4)&&(f2==3||f2==4)))){
		COUT="1100";
		cout<<COUT;
		return 0;
	}
	//判断是否相邻
	if(abs(f2-f1)>1 || (f1==2 && f2==3) || (f1==3 && f2==2)){
		COUT="1110";
		cout<<COUT;
		return 0;
	}
	COUT="1111";
	cout<<COUT;
	return 0;
} 
