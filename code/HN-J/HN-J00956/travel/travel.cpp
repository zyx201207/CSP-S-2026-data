#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n[105];
	for(int i=0;i<=6;i++){
		cin >> n[i];
		if(n[1]==n[4]){
		cout << 1;
		}else{
			cout << 0;
		}
		if(n[2]==n[5]){
			cout << 1;
		}else{
			cout << 0;
		}
		if(n[3]=='A'&&n[6]=='B'){
			cout << 1;
		}else if(n[3]=='B'&&n[6]=='A'){
			cout << 1;
		}else if(n[3]=='B'&&n[6]=='C'){
			cout << 1;
		}else if(n[3]=='C'&&n[6]=='B'){
			cout << 1;
		}else if(n[3]=='D'&&n[6]=='F'){
			cout << 1;
		}else if(n[3]=='F'&&n[3]=='D'){
			cout << 1;
		}else{
			cout<< 0;
		}
 	}
	return 0;
}
 
