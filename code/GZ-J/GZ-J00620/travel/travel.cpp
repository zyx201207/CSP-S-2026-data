//GZ-J00620 ¹ùå°Ğù 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string h1,h2,z1,z2;
	cin>>h1>>z1>>h2>>z2;
	int hao1=(h1[0]-'0')*10+(h1[1]-'0');
	int hao2=(h2[0]-'0')*10+(h2[1]-'0');
	int hang1=(z1[0]-'0')*10+(z1[1]-'0');
	int hang2=(z2[0]-'0')*10+(z2[1]-'0');
	int lyl=z1[2]-'A'+1;
	int yly=z2[2]-'A'+1;
	if(hao1==hao2){
		cout<<"1";
		if(hang1==hang2){
			cout<<"1";
			if(lyl<=3 && yly<=3){
				cout<<"1";
				if(abs(lyl-yly)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(lyl>3 && yly>3){
				cout<<"11";
				return 0;
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
		cout<<"0000";
		return 0;
	}
	return 0;
}
