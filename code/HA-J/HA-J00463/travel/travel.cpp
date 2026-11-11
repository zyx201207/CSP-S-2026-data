#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c[0]==cc[0] && c[1]==cc[1]){
		cout<<"1";
		if(s[1]==ss[1] && s[0]==ss[0]){
			cout<<"1";
			char a=s[2],b=ss[2];
			if(a=='A'){
				if(b=='B' || b=='C'){
					cout<<"1";
					if(b=='B'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
				}
			}else if(a=='B'){
				if(b=='A' || b=='C'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else if(a=='C'){
				if(b=='A' || b=='B'){
					cout<<"1";
					if(b=='B'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
				}
			}else if(a=='D'){
				if(b=='F'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else if(a=='F'){
				if(b=='D'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000"<<endl;
	}
	return 0;
}
