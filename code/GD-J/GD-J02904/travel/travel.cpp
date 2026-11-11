#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);	
string a,b,x,y;
cin>>a>>b>>x>>y;
if(a!=x){
	cout<<"0";
	cout<<"0";
	cout<<"0";
	cout<<"0";
	return 0;
}
else if(a==x){
	cout<<"1";
	if(b[0]!=y[0] or b[1]!=y[1]){
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	else if(b[0]==y[0]&&b[1]==y[1]){
		cout<<"1";
		if(b[2]=='A'&&y[2]=='B' or b[2]=='A'&&y[2]=='C' or b[2]=='B'&&y[2]=='A' or b[2]=='B'&&y[2]=='C' or b[2]=='C'&&y[2]=='A' or b[2]=='C'&&y[2]=='B' or b[2]=='D'&&y[2]=='F' or b[2]=='F'&&y[2]=='D'){
			cout<<"1";
			if(b[2]=='A'&&y[2]=='B' or b[2]=='B'&&y[2]=='A' or b[2]=='B'&&y[2]=='C' or b[2]=='C'&&y[2]=='B' or b[2]=='D'&&y[2]=='F' or b[2]=='F'&&y[2]=='D'){
				cout<<"1";
				return 0;
			}
			else{
				cout<<"0";
				return 0;
			}
		}
		else{
			cout<<"0";
			cout<<"0";
			return 0;
		}
	}
}
} 








