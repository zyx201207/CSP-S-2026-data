#include <bits/stdc++.h>
using namespace std;
int a[3],c[3];
char b[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		cin>>a[1]>>c[1]>>b[1]>>a[2]>>c[2]>>b[2];
	if(a[1]==a[2]){
		cout<<"1";
		if(c[1]==c[2]){
			cout<<"1";
			if(b[1]=='A'||b[1]=='B'||b[1]=='C'){
				if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
					cout<<"1";
					if(b[1]=='A'){
						if(b[2]=='B'){
							cout<<"1";
						}else{
							cout<<"0";
						}
					}
					else if(b[1]=='B'){
						if(b[2]=='C'||b[2]=='A'){
							cout<<"1";
						}else{
							cout<<"0";
						}
					}
					else if(b[1]=='C'){
						if(b[2]=='B'){
							cout<<"1";
						}else{
							cout<<"0";
						}
					}					
				}
				else{
					cout<<"00";
				}
			}
			else if(b[1]=='F'||b[1]=='D'){
				if(b[2]=='F'||b[2]=='D'){
					cout<<"11";
				}
			}
			else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
