#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string S1,S2;
	int c1,c2;
	cin>>c1>>S1>>c2>>S2;
	if(c1==c2){
		cout<<"1";
		int s1=S1[0]*10+S1[1],s2=S2[0]*10+S2[1];
		char s1_=S1[2],s2_=S2[2];
		if(s1==s2){
			cout<<"1";
			if(s1_=='F'||s1_=='D'){
				if(s2_=='F'||s2_=='D'){
					cout<<"11";
					return 0;
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else{
				if(s2_=='F'||s2_=='D'){
					cout<<"00";
					return 0;
				}
				else{
					cout<<"1";
					if(s1_=='A'&&s2_=='B'||s1_=='B'&&s2_=='A'||s1_=='C'&&s2_=='B'||s1_=='B'&&s2_=='C'){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
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
	return 0;
}
