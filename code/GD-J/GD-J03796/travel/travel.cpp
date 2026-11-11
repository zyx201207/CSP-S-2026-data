#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,a1,b1,a2,b2;
	string x,y;
	cin>>a>>x>>b>>y;
	a1=(x[0]-'0')*10+(x[1]-'0');
	b1=(y[0]-'0')*10+(y[1]-'0');
	if(x[2]=='A') a2=1;
	if(x[2]=='B') a2=2;
	if(x[2]=='C') a2=3;
	if(x[2]=='D') a2=4;
	if(x[2]=='F') a2=5;
	if(y[2]=='A') b2=1;
	if(y[2]=='B') b2=2;
	if(y[2]=='C') b2=3;
	if(y[2]=='D') b2=4;
	if(y[2]=='F') b2=5;
	if(a==b){
		cout<<"1";
		if(a1==b1){
			cout<<"1";
			if((a2<=3 && b2<=3) || (a2>3 && b2>3)){
				cout<<"1";
				if(abs(a2-b2)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
