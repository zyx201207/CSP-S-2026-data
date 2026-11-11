#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<"1";
			if((e<='C'&&f<='C')||(e>='D'&&f>='D')){
				cout<<"1";
				if((e=='A'&&f=='B')||(e=='C'&&f=='B')||(e=='D'&&f=='F')){
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
