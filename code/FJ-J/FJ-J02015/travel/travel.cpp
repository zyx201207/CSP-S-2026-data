#include<bits/stdc++.h>
using namespace std;
char c1[3],s1[3],c2[3],s2[3];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0; i<=3; i++){
		cin>>c1[i];
	}
	for(int i=0; i<=3; i++){
		cin>>s1[i];
	}
	for(int i=0; i<=3; i++){
		cin>>c2[i];
	}
	for(int i=0; i<=2; i++){
		cin>>s2[i];
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			for(int i='A';i<='F';i++){
				if(s1[2]==i){
					for(int j='A';j<='F';j++){
						if(s2[2]==i){
							cout<<"1";
						}
						cout<<"0";
						break;
					}
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		cout<<"1";
	}else{
		cout<<"0";
	}
		return 0;
}
