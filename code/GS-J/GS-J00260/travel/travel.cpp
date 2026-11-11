#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[100],c[100];
	char b[100],d[100];
	cin>>a>>b>>c>>d;
	if((a[0]==c[0])&&a[1]==c[1]){
		if((b[0]==d[0])&&b[1]==d[1]){
			if((b[2]=='A'&&(d[2]=='B'||d[2]=='C'))||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&(d[2]=='B'||d[2]=='A'))){
				if(b[2]=='B'||d[2]=='B'){
					cout<<1111;
				}
				else{
					cout<<1110;
				}
			}
			else if((b[2]=='D'&&d[2]=='E')||(b[2]=='E'&&d[2]=='D')){
				cout<<1111;
			}
			else{
				cout<<1100;
			}
		}
		else{
			cout<<1000;
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
