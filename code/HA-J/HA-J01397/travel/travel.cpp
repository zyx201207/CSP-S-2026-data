#include<bits/stdc++.h>
using namespace std;
char a[10],b[10],c[10],d[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	for(int i=1;i<=2;i++){
		cin>>c[i];
	}
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	if(a[1]==c[1]&&a[2]==c[2]){
		if(b[1]==d[1]&&b[2]==d[2]){
			if(b[3]=='A'&&d[3]=='B'||b[3]=='A'&&d[3]=='C'||b[3]=='B'&&d[3]=='A'||b[3]=='B'&&d[3]=='C'||b[3]=='C'&&d[3]=='A'||b[3]=='C'&&d[3]=='B'||b[3]=='D'&&d[3]=='F'||b[3]=='F'&&d[3]=='D'){
				if(b[3]=='A'&&d[3]=='B'||b[3]=='B'&&d[3]=='A'||b[3]=='B'&&d[3]=='C'||b[3]=='C'&&d[3]=='B'||b[3]=='D'&&d[3]=='F'||b[3]=='F'&&d[3]=='D'){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
