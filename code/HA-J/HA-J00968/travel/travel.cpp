#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				cout<<"000";
				return 0;
				break;
			}else{
				cout<<"1";
				break;
			}
		}
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				cout<<"1";
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			if(s2[2]=='D'||s2[2]=='E'){
				cout<<"1";
			}else{
				cout<<"00";
				return 0;
			}
		}
		if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
			cout<<"1";
		}else{
			cout<<"0";
		}
		
	}else{
		cout<<"0000";
	}
	return 0;
}
