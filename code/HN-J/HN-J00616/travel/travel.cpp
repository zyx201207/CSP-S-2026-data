#include<iostream>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1[0]!=c3[0] || c1[1]!=c3[1]){
		cout<<"0000";
	}
	else{
		if(c2[1]!=c4[1]){
			cout<<"1000";
		}
		else{
			if(c2[2]=='D' && c4[2]=='A') cout<<"1100";
			else if(c2[2]=='D' && c4[2]=='B') cout<<"1100";
			else if(c2[2]=='D' && c4[2]=='C') cout<<"1100";
			else if(c2[2]=='F' && c4[2]=='A') cout<<"1100";
			else if(c2[2]=='F' && c4[2]=='B') cout<<"1100";
			else if(c2[2]=='F' && c4[2]=='C') cout<<"1100";
			else if(c2[2]=='A' && c4[2]=='D') cout<<"1100";
			else if(c2[2]=='A' && c4[2]=='F') cout<<"1100";
			else if(c2[2]=='B' && c4[2]=='D') cout<<"1100";
			else if(c2[2]=='B' && c4[2]=='F') cout<<"1100";
			else if(c2[2]=='C' && c4[2]=='D') cout<<"1100";
			else if(c2[2]=='C' && c4[2]=='F') cout<<"1100";
			else{
				if(c2[2]=='A' && c4[2]=='B') cout<<"1111";
				else if(c2[2]=='B' && c4[2]=='A') cout<<"1111";
				else if(c2[2]=='C' && c4[2]=='B') cout<<"1111";
				else if(c2[2]=='B' && c4[2]=='C') cout<<"1111";
				else if(c2[2]=='D' && c4[2]=='F') cout<<"1111";
				else if(c2[2]=='F' && c4[2]=='D') cout<<"1111";
				else{
					cout<<"1110";
				}
			}
		}
	}
	return 0;
}
