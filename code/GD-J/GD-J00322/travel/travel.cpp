#include<bits/stdc++.h>
using namespace std;
char a[1050];
int main(){
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	if(a[1]==a[6]&&a[2]==a[7]){
		if(a[3]==a[8]&&a[4]==a[9]){
			if(a[5]=='E'||a[5]=='D'){
				if(a[10]=='D'||a[10]=='E') cout<<"1111";
				else cout<<"1100";
			}
			if(a[5]=='A'||a[5]=='C'){
				if(a[10]=='D'||a[10]=='E') cout<<"1100";
				else if(a[10]=='B') cout<<"1111";
				else cout<<"1110";
			}
			if(a[5]=='B'){
				if(a[10]=='D'||a[10]=='E') cout<<"1100";
				else cout<<"1111";
			}
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
} 
