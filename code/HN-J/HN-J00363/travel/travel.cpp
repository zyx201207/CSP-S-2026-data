#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;//输入  01 02A 01 02B 
	if((c1[0]==c2[0])&&(c1[1]==c2[1])){//同车厢 0=0，1=1 
		cout<<"1";//1
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){//同行 0=0,2=2
			cout<<"1";//11
			if(((s1[2]=='A')||(s1[2]=='B')||(s1[2]=='C'))&&((s2[2]=='A')||(s2[2]=='B')||(s2[2]=='C'))){//同侧 
				cout<<"1";//111
				if(((s1[2]=='A'||s1[2]=='B')&&(s2[2]=='A'||s2[2]=='B'))||((s1[2]=='B'||s1[2]=='C')&&(s2[2]=='B'||s2[2]=='C'))){//相邻 
					cout<<"1";//1111
				}
				else{
					cout<<"0";//1110
				}
			}
			else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				cout<<"11";//1111
			}
			else{
				cout<<"00";//1100
			}
		}
		else{
			cout<<"000";//1000
		}
	}
	else{
		cout<<"0000";//0000
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
