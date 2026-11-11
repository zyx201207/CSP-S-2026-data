//GZ-J00378,贵阳市中天中学，郑景元 
#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s2[0]==s1[0]&&s2[1]==s1[1]){
			if(s1[3]=='A'){
				if(s2[3]=='B'){
					cout<<"1111";
				}else if(s2[3]=='C')cout<<"1110";
				else cout<<"1110";
			}
			else if(s1[3]=='B'){
				if(s2[3]=='A'||s2[3]=='C'){
					cout<<"1111";
				}
				else cout<<"1100";
			}
			else if(s1[3]=='C'){
				if(s2[3]=='B'){
					cout<<"1111";
				}else if(s2[3]=='A')cout<<"1110";
				else cout<<"1100";
			}else if((s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s2[3]=='D')){
				cout<<"1111";
			}
			else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}
	else cout<<"0000";
	return 0;
}
