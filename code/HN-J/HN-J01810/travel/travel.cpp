#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[4];
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	if(a[0]==a[2]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a[1][1]==a[3][1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(a[1][1]==a[3][1]){
		if(a[1][2]=='D'&&a[3][2]=='C'||a[1][2]=='C'&&a[3][2]=='D'){
			cout<<"00";
			return 0;
		}else{
			cout<<"1";
		}
	}else{
		cout<<"00";
		return 0;
	}
	if(a[3][2]-a[1][2]==1||a[1][2]-a[3][2]==1){
		if(a[1][2]=='D'&&a[3][2]=='C'||a[3][2]=='D'&&a[1][2]=='C'){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else{
		cout<<"0";
	}
	return 0;
}
