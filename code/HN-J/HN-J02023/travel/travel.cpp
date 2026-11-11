#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ra,xa;
	string rb,xd;
	cin>>ra>>rb>>xa>>xd;
	if(ra==xa){
		cout<<"1";
		if(rb[0]==xd[0]&&rb[1]==xd[1]){
			cout<<"1";
			if(rb[2]="A"&&xd[2]="B"||rb[2]="A"&&xd[2]="C"||rb[2]="B"&&xd[2]="A"||rb[2]="B"&&xd[2]="C"||rb[2]="C"&&xd[2]="A"||rb[2]="C"&&xd[2]="B"||rb[2]="D"&&xd[2]="F"||rb[2]="F"&&xd[2]="D"){
				cout<<"1";
				if(rb[2]="A"&&xd[2]="B"||rb[2]="B"&&xd[2]="A"||rb[2]="B"&&xd[2]="C"||rb[2]="C"&&xd[2]="B"||rb[2]="D"&&xd[2]="F"||rb[2]="F"&&xd[2]="D"){
					cout<<"1";
					return 0;
				}else{
					cout<<"1110";
					return 0; 
				}
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
