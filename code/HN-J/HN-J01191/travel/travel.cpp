#include<bits/stdc++.h>
using namespace std;
string c, d;
int a, b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> c >> b >> d;
	if(a == b){//是否在同一节车厢 
		cout << "1";
		//是否在同一排
		if(c[0] == d[0] && c[1] == d[1]){
			cout << "1";
			//是否在同一侧
			if(c[2]=='D'){
				if(d[2] =='F'){
					cout << "11";
					/*
					if(c[2]>d[2]){
						if(c[2]-d[2] == 1){
							cout << "1";
						}else{
							cout << "0";
						}
					}else{
						if(d[2]-c[2] == 1){
							cout << "1";
						}else{
							cout << "0";
						}
					}
					*/
				}else{
					cout <<" 00";
				}
			}else if(c[2] == 'F'){
				if(d[2] == 'D'){
					cout << "11";
					/*
					if(c[2]>d[2]){
						if(c[2]-d[2] == 1){
							cout << "1";
						}else{
							cout << "0";
						}
					}else{
						if(d[2]-c[2] == 1){
							cout << "1";
						}else{
							cout << "0";
						}
					}
					*/
				}else{
					cout << "00";
				}
			}else{
				if(d[2]=='D' || d[1]=='F'){
					cout<< "00";
				}else{
					cout << "1";
					//
					if(c[2]>d[2]){
						if(c[2]-d[2] == 1){
							cout << "1";
						}else{
							cout << "0";
						}
					}else{
						if(d[2]-c[2] == 1){
							cout << "1";
						}else{
							cout << "0";
						}
					}
					//
				}
			}
			
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	return 0; 
}
