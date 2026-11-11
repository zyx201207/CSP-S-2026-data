#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char seatt[3]={'A','B','C'};
	if (c1==c2){
		cout<<"1";
		if (s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			if (s1[2]=='D' || s1[2]=='F'){
				if (s2[2]=='D' || s2[2]=='F'){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
			}
			else{
				if (s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
					cout<<"1";
					int ss1=0,ss2=0;
					for (int i=0;i<3;i++){
						if (s1[2]==seatt[i]){
							ss1=i+1;
						}
						if (s2[2]==seatt[i]){
							ss2=i+1;
						}
					}
					if (ss1-ss2==1 || ss1-ss2==-1){
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
