#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	int ascii[999];
	ascii[0]=c1[0];
	ascii[1]=c1[1];
	
	ascii[2]=s1[0];
	ascii[3]=s1[1];
	
	ascii[4]=c2[0];
	ascii[5]=c2[1];
	ascii[6]=c2[2];
	
	ascii[7]=s2[0];
	ascii[8]=s2[1];
	ascii[9]=s2[2];
	if(ascii[0]==ascii[2]){
		if(ascii[1]==ascii[3]){
			cout<<"1";
			if(ascii[4]==ascii[7]){
				if(ascii[5]==ascii[8]){
					cout<<"1";
					if(ascii[6]==69&&ascii[9]==68){
						cout<<"11";
						return 0;
					}
					else if(ascii[6]==68&&ascii[9]==69){
						cout<<"11";
					}
					else if(ascii[6]<=67&&ascii[9]<=67){
						cout<<"1";
						if(ascii[6]-ascii[9]==1||ascii[9]-ascii[6]==1){
							cout<<"1";
							return 0;
						}
						else{
							cout<<"0";
							return 0;
						}
					}
					else{
						cout<<"00";
						return 0;
					}
				}
				else{
					cout<<"000";
					return 0;
				}
			}
			else{
				cout<<"000";
				return 0;
			}
		}
			
		
		
		else{
			cout<<"0000";
			return 0;
		}
	}
	else{
		
		cout<<"0000";
		return 0;
	}
	return 0;
}