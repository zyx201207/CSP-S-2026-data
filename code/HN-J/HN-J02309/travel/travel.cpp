#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travei.out","w",stdout);
	string a,b,c,d;
	cin>>a>>c>>b>>d;
	char e=c[2],f=d[2];
	if(a==b){
		cout<<"1";
		if(c[1]==d[1]){
			cout<<"1";
			if(e=='d'||e=='f'){
				if(f!='d'&&f!='f'){
				cout<<"00";
				}else{
					if(f=='d'||f=='f'){
					if(e!='d'&&e!='f'){
						cout<<"00";
					}
						}else {
						cout<<"1";
								if(e+2==f+1||e-2==f-1){
							cout<<"1";
						}else cout<<"0";}
				}
			}else{
				if(f=='d'||f=='f'){
					if(e!='d'&&e!='f'){
						cout<<"00";
					}else {
					cout<<"1";
								if(e+2==f+1||e-2==f-1){
							cout<<"1";
						}else cout<<"0";}
				}else {
				cout<<"1";
							if(e+2==f+1||e-2==f-1){
							cout<<"1";
						}else cout<<"0";}
			}
		}else cout<<"000";	
	}else cout<<"0000"; 
	
	return 0;
}
