#include<bits/stdc++.h>
using namespace std;
long long a,x,ab,xy;
string b,y;
bool f,f1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')f=0;
	else f=1;
	if(y[2]=='A'||y[2]=='B'||y[2]=='C')f1=0;
	else f1=1;
	ab=(b[0]-'0')*10+(b[1]-'0');
	xy=(y[0]-'0')*10+(y[1]-'0');
	if(a!=x){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(ab!=xy){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(f!=f1){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if((b[2]=='A'&&y[2]=='B')||(b[2]=='B'&&y[2]=='C')||(b[2]=='D'&&y[2]=='F')||(b[2]=='B'&&y[2]=='A')||(b[2]=='C'&&y[2]=='B')||(b[2]=='F'&&y[2]=='D')){
		cout<<"1";
	}
	else {
		cout<<"0";
	}
	return 0;
} 

