#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	char R[5],X[5],R1[5],X1[5];
	cin>>R[1]>>R[2]>>R1[1]>>R1[2]>>R1[3]>>X[1]>>X[2]>>X1[1]>>X1[2]>>X1[3];
	//车厢 
	if(R[2]==1||X[2]==1){
		cout<<"0000";
		return 0;
	}
	if(R1[3]==X1[3]){
		cout<<"0000";
		return 0;
	}
	if(R[2]!=X[2]){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	//排 
	if(R1[1]==X1[1]&&R1[2]==X1[2]){
		cout<<"1";
		//过道 
		if(R1[3]>='A'&&R1[3]<='C'&&X1[3]>='A'&&X1[3]<='C'||R1[3]>='D'&&R1[3]<='F'&&X1[3]>='D'&&X1[3]<='F'){
			cout<<"1";
			//相邻 
			if(R1[3]==X1[3]+1||R1[3]==X1[3]-1){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
		return 0;
	}
	return 0;
} 
