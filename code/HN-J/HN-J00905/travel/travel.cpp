#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]+b[1]-'0'==d[0]+d[1]-'0'){
			cout<<"1";
			if(b[2]=='D'||b[2]=='F'){
				if(d[2]=='D'||d[2]=='F'&&c[2]!=d[2]){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
			}
			else if(b[2]=='C'||b[2]=='D'){
				if(d[2]=='D'||d[2]=='C'){
					cout<<"00";
					return 0;
				}
				else if(b[2]-d[2]<3&&d[2]-b[2]<3){
					cout<<"1";
				if(b[2]-d[2]==1||d[2]-b[2]==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
			}
			else if(b[2]-d[2]<3&&d[2]-b[2]<3){
				cout<<"1";
				if(b[2]-d[2]==1||d[2]-b[2]==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}

