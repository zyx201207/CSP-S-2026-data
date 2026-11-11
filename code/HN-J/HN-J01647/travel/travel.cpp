#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c,e,f;
	string b,d;
	cin>>a>>e>>b>>c>>f>>d;
	if(a==c){
		cout<<1;
		if(e==f){
			cout<<1;
			if( (b[0]>='A'&&b[0]<='C'&&d[0]>='A'&&d[0]<='C')||(b[0]>='D'&&b[0]<='F'&&d[0]>='D'&&d[0]<='F') ){
				cout<<1;
				char r=b[0],x=d[0];
				if( (r=='A'&&x=='B')||(r=='B'&&x=='A')||(r=='B'&&x=='C')||(r=='C'&&x=='B')||(r=='D'&&x=='F')||(r=='F'&&x=='D')){
					cout<<1;
				}else{
					cout<<0;
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

