#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d,X,Y;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	X=X+b[0]+b[1];
	Y=Y+d[0]+d[1];
	x=b[2];
	y=d[2];
	if(a==c){
		cout<<1;
		if(X==Y){
			cout<<1;
			if((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='A'&&y=='C')||(x=='C'&&y=='A')||(x=='B'&&y=='C')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
				cout<<1;
				if((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
					cout<<1;
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
