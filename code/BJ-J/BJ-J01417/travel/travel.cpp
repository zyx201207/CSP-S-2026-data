#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string s,z;
char a2[4],b2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>s>>z;
	for(int i=1;i<=s.size();i++){
		a2[i]=s[i];
	}
	for(int i=1;i<=z.size();i++){
		b2[i]=z[i];
	}
	if(a1==b1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a2[1]==b2[1]&&a2[2]==b2[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a2[3]=='A'&&b2[3]=='B'){
		cout<<"1";
	}else{
		if(a2[3]=='A'&&b2[3]=='C'){
			cout<<"1";
		}else{
			if(a2[3]=='B'&&b2[3]=='A'){
				cout<<"1";
			}else{
				if(a2[3]=='B'&&b2[3]=='C'){
					cout<<"1";
				}else{
					if(a2[3]=='C'&&b2[3]=='A'){
						cout<<"1";
					}else{
						if(a2[3]=='C'&&b2[3]=='B'){
							cout<<"1";
						}else{
							if(a2[3]=='D'&&b2[3]=='F'){
								cout<<"1";
							}else{
								if(a2[3]=='F'&&b2[3]=='D'){
									cout<<"1";
								}else{
									cout<<"0";
								}
							}
						}
					}
				}
			}
		}
	}
	if(a2[3]=='A'&&b2[3]=='B'){
		cout<<"1";
	}else{
		if(a2[3]=='B'&&b2[3]=='A'){
			cout<<"1";
		}else{
			if(a2[3]=='B'&&b2[3]=='C'){
				cout<<"1";
			}else{
				if(a2[3]=='C'&&b2[3]=='B'){
					cout<<"1";
				}else{
					if(a2[3]=='D'&&b2[3]=='F'){
						cout<<"1";
					}else{
						if(a2[3]=='F'&&b2[3]=='D'){
							cout<<"1";
						}else{
							cout<<"0";
						}
					}
				}
			}
		}
	}
	return 0;
}
