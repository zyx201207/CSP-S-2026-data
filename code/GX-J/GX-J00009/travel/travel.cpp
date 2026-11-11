#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string co,so,ct,st;
	int cnt = 0;
	int a = 0;
	cin >> co >> so >> ct >> st;
	if(co==ct){
		cout << "1";
		a++;
	}else{
		cout <<"0000"; 
		return 0;
	}
	for(int i = 0;i <2;i++){
		if(so[i]== st[i]){
			cnt++;
		}
	}
	if(cnt == 2){
		cout << "1";
		a++;	
	}else{
		cout << "0";
	}
	if(cnt == 2){
		for(int i=2;i<=2;i++){
			if(so[i] == 'A' || so[i] == 'B' ||so[i] == 'C'){
				if(st[i] == 'A' || st[i] == 'B' ||st[i] == 'C'){
					cout <<"1";
					a++;
				}
				else{
					cout << "0";
				}
			}else{
				if(st[i] == 'D' || st[i] == 'F'){
					cout <<"1";
					a++;
				}
				else{
					cout << "0";
				}	
			}
		}
	}else{
		cout << "0";
	}
	if(a == 3){
		for(int i = 2;i <= 2;i++){
			if(char(so[i] + int('A'-'B'))==st[i] || char(so[i] - int('A'-'B'))==st[i]){
				cout << "1";
			}
			else{
				cout << "0";
			}
		}
		
		
	}else{
		cout << "0";
	}
	
	
	return 0;
}
