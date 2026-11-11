#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c){
		cout<<"1";
		if(b==d){
			cout<<"1";
			if((e<='C' and e>='A') and (f<='C' and f>='A')){
				cout<<"1";
				if((e=='A' and f=='C') or (f=='A' and e=='C')){
					cout<<"0";
					return 0;
				}else{
					cout<<"1";
					return 0;
				}
			} 
			if((e<='E' and e>='D') and (f<='E' and f>='D')){
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
