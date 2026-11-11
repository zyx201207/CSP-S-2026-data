#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	//a为R所在车厢 b为X所在车厢 x为a所在座位 y为X所在座位 
	cin>>a>>x>>b>>y;
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<1;
		if(x[0]==y[0]&&x[1]==y[1]){
			cout<<1;
			if(x[2]>='A'&&x[2]<='C'&&y[2]>='A'&&y[2]<='C'){
				cout<<1;
				if(x[2]=='B'||y[2]=='B') cout<<1;
				else cout<<0;
			}
			else{
				if((x[2]=='D'||x[2]=='F')&&(y[2]=='D'||y[2]=='F')){
					cout<<11;
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
