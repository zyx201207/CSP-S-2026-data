#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
string c1,c2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<1;
		c1+=b1[0];
		c1+=b1[1];
		c2+=b2[0];
		c2+=b2[1];
		if(c1==c2){
			cout<<1;
			char x,y;
			x=b1[2];
			y=b2[2];
			if(((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))||((x=='F'||x=='D')&&(y=='F'||y=='D'))){
				cout<<1;
				if(x==y-1||y==x-1){
					cout<<1<<endl;
				}
				else{
					cout<<"0"<<endl;
				}
			}
			else{
				cout<<"00"<<endl;
			}
		}
		else{
			cout<<"000"<<endl;
		}
	}
	else{
		cout<<"0000"<<endl;
	}
	return 0;
}
