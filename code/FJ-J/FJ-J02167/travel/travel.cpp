#include<bits/stdc++.h>
using namespace std;

int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b[2]==68){
		c1=1;
	}
	else if(b[2]==69){
		c1=1;
	}
	else{
		c1=2;
	}
	if(d[2]==68){
		c2=1;
	}
	else if(d[2]==68){
		c2=1;
	}
	else{
		c2=2;
	}
	if(a==c){
		cout<<1;
		if(b[1]==d[1]&&b[0]==d[0]){
				cout<<1;
				if(c1==c2){
					cout<<1;
					if(b[2]-d[2]==1||b[2]-d[2]==-1){
						cout<<1;
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
}
