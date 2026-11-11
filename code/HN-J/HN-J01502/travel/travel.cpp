#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c1,c3;
	string c2,c4;
	string s1="0000";
	cin>>c1>>c2>>c3>>c4;
	if(c1>=16||c1<=1||c3>=16||c3<=1){
		return 0;
	}
	if(c1==c3){
		s1[0]='1';
		if(c2[1]==c4[1]&&c2[0]==c4[0]){
			s1[1]='1';
			if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(c4[2]=='A'||c4[2]=='B'||c4[2]=='C')){
				s1[2]='1';
				if(c2[2]+1==c4[2]||c2[2]-1==c4[2]){
					s1[3]='1';
				}
				else{
					s1[3]='0';
				}
			}
			else if((c2[2]=='D'||c2[2]=='F')&&(c4[2]=='D'||c4[2]=='F')){
				s1[2]='1';
				if(c2[2]+1==c4[2]||c2[2]-1==c4[2]){
					s1[3]='1';
				}
				else{
					s1[3]='0';
				}
			}
			else{
				s1[2]='0';
			}	
		}
	}
	cout<<s1;
	return 0;
}
