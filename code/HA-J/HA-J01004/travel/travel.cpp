#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if((e=='A'||e=='B'||e=='C')&&(f=='A'||f=='B'||f=='C')){
				cout<<1;
				if(e=='B'||f=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if((e=='D'||e=='F')&&(f=='D'||f=='F')){
				cout<<"11";
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
