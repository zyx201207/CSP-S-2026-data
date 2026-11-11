#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char n1=s1[2],n2=s2[2];
	int x=n1-'@',y=n2-'@';
	if (c1==c2){
		cout<<"1";
		if (s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<"1";
			if (x>3&&y>3){
				cout<<"1";
				if (abs(x-y)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if (x<=3&&y<=3){
				cout<<"1";
				if (abs(x-y)==1){
					cout<<"1";
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
	return 0;
} 
