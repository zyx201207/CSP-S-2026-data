#include<bits/stdc++.h>
using namespace std;
string a[10];
int main(){
	freopen("travel.in","r","std.in");
	freopen("travel.out","w","std.out");
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=4;i++){
		cin>>a[i];
	}
	if(a[1]==a[3]){
		cout<<1;
		if(a[2][1]==a[4][1] && a[2][0]==a[4][0]){
			cout<<1;
			if(a[2][2]=='C' && a[4][2]=='A'){
				cout<<"10";
			}else if(a[2][2]=='C' && a[4][2]=='B'){
				cout<<"11";
			}else if(a[2][2]=='D' && a[4][2]=='F'){
				cout<<"11";
			}else if(a[4][2]=='C' && a[2][2]=='A'){
				cout<<"10";
			}else if(a[4][2]=='C' && a[2][2]=='B'){
				cout<<"11";
			}else if(a[4][2]=='D' && a[2][2]=='F'){
				cout<<"11";
			}else if(a[2][2]=='A' && a[4][2]=='B'){
				cout<<"11";
			}else if(a[2][2]=='B' && a[4][2]=='A'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
