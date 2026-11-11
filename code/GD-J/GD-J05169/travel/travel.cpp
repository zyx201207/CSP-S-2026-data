#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char a[10],b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1;
	for(int i=1;i<=3;i++)cin>>a[i];
	cin>>c2;
	for(int i=1;i<=3;i++)cin>>b[i];
	if(c1==c2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	for(int i=1;i<=2;i++){
		if(a[1]==b[1]&&a[2]==b[2]){
			cout<<"1";
			break;
		}
		else {
			cout<<"0";
			break;
		}
	}
	for(int i=1;i<=3;i++){
		if(a[1]==b[1]&&a[2]==b[2]){
			if((a[3]=='A'&&(b[3]=='B'||b[3]=='C'))||(a[3]=='B'&&(b[3]=='A'||b[3]=='C'))||(a[3]=='C'&&(b[3]=='B'||b[3]=='A'))||(a[3]=='D'&&b[3]=='F')||(a[3]=='F'&&b[3]=='D')){
				cout<<"1";
				break;
			}
			else{
				cout<<"0";
				break;
			}
		}
		else{
				cout<<"0";
				break;
			}
	}
	for(int i=1;i<=3;i++){
		if(a[1]==b[1]&&a[2]==b[2]){	
			if((a[3]=='A'&&(b[3]=='B'||b[3]=='C'))||(a[3]=='B'&&(b[3]=='A'||b[3]=='C'))||(a[3]=='C'&&(b[3]=='B'||b[3]=='A'))||(a[3]=='D'&&b[3]=='F')||(a[3]=='F'&&b[3]=='D')){
				if((a[3]=='A'&&b[3]=='B')||(a[3]=='B'&&b[3]=='A')||(a[3]=='C'&&b[3]=='B')||(a[3]=='B'&&b[3]=='C')||(a[3]=='C'&&b[3]=='D')||(a[3]=='D'&&b[3]=='C')||(a[3]=='D'&&b[3]=='F')||(a[3]=='F'&&b[3]=='D')){
					cout<<"1";
					break;
				}
				else{
					cout<<"0";
					break;
				}
			}
			else{
					cout<<"0";
					break;
				}
		}
		else{
				cout<<0;
				break;
			}	
	}
	return 0;
}
