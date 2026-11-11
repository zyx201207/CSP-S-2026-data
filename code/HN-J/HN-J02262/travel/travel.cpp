#include <bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char zm1,zm2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>zm1>>c2>>s2>>zm2;
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
				cout<<"1";
				if(zm1=='A'){
					if(zm2=='B'||zm2=='C'){
						cout<<"1";
						if(zm2=='B'){
							cout<<"1";
						}else{
							cout<<"0";
						}
					}
				}else if(zm1=='B'){
						if(zm2=='A'||zm2=='C'){
							cout<<"1";
							cout<<"1";
					}
				}else if(zm1=='C'){
						if(zm2=='B'||zm2=='A'){
							cout<<"1";
							if(zm2=='B'){
							cout<<"1";
						}else{
							cout<<"0";
						}
					}
				}else if(zm1=='D'){
						if(zm2=='F'){
							cout<<"1";
							cout<<"1";
						}
					}else if(zm1=='F'){
						if(zm2=='D'){
							cout<<"1";
							cout<<"1";
						}
					}else{
						cout<<"0";
					}
			}else{
				cout<<"000";
			}
		}else{
			cout<<"0000";
		}	
	return 0;
}
