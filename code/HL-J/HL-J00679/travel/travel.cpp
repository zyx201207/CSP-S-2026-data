#include<bits\stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2];
	char b=s2[2];
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[1]){
			cout<<"1";
			if(a=='A'||a=='B'||a=='C'){
				if(b=='A'||b=='B'||b=='C'){
					cout<<"1";
				}else{
					cout<<"0";
				}if(a=='B'||b=='B'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(b=='D'||b=='F'){
				cout<<"1";
			}else{
				cout<<"0";
			}	
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
fclose(stdin);
fclose(stdout);
	return 0;
}
