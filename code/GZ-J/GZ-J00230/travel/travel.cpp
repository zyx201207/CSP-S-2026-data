// Gz-J00230 黔西市思源实验学校 许邴淳
#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'||s1[2]=='D'||s1[2]=='F'&&s1[2]=='D'||s1[2]=='F'){
				if(s1[2]-'0'+1==s2[2]-'0'||s1[2]-'0'-1==s2[2]-'0'){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
} 
