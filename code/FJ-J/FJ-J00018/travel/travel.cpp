#include <bits/stdc++.h>
using namespace std;

int main(){
	// 定义 
	int rp,xp;
	char rz[3],xz[3];
	
	// 输入 
	cin>>rp;
	for (int i=0;i<3;i++){
		cin>>rz[i];
	}
	cin>>xp;
	for (int i=0;i<3;i++){
		cin>>xz[i];
	}
	
	// 判断
	// 判断车厢号 
	if (rp==xp){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	// 判断是否在同一排
	if (rz[0]==xz[0] && rz[1]==xz[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	
	// 判断是否在同一侧及判断是否相邻
	if (rz[2]=='D' || xz[2]=='D'){
		if (rz[2]=='F' || xz[2]=='F'){
			cout<<"11";
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	else if (abs(rz[2] - xz[2])== 1){
		cout<<"11";
	}
	else {
		cout<<"10";
	}
	
	return 0;
}
