//GZ-J00069 遵义市新蒲新区滨湖中学 刘李皓阳  
#include<bits/stdc++.h>
using namespace std;	
int c1,c2,ss1,ss2,ans;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ss1 = (s1[0]-'0')*10+s1[1] -'0';
	ss2 = (s2[0]-'0')*10+s2[1] -'0';
	if(c1 == c2){
		if(ss1 == ss2){
			if(s1[2] =='A'||s1[2] =='B'||s1[2] =='C'&&s2[2]=='D'||s2[2]=='F'){
				cout<<"1100"; 
			}
			if(s2[2] =='A'||s2[2] =='B'||s2[2] =='C'&&s1[2]=='D'||s1[2]=='F'){
				cout<<"1100"; 
			}
			if(s1[2] == 'A'){
				if(s2[2] == 'B'){
					cout<<"1111";
				}
				if(s2[2] == 'C'){
					cout<<"1110"; 	
				}
			}
			if(s1[2] == 'B'){
				if(s2[2] == 'A'||s2[2] == 'C'){
					cout<<"1111";
				}
			}
			if(s1[2] == 'C'){
				if(s2[2] == 'A'){
					cout<<"1110"; 
				}
				if(s2[2] == 'B'){
					cout<<"1111";
				}
			}
			if(s1[2] == 'D'){
				if(s2[2] == 'F'){
					cout<<"1111";
				}
			}
			if(s1[2] == 'F'){
				if(s2[2] == 'D'){
					cout<<"1111";
				}
			}
		}
		if(ss1 != ss2) cout<<"1000";
	}
	if(c1 != c2) cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
