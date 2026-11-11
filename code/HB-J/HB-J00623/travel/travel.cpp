#include<bits/stdc++.h>
using namespace std;
string s_s1,s_s2,s_s3,s_s4;
int judge_x(char a){
	if(a=='A'||a=='B'||a=='C') return 1;
	else return 2;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s_s1>>s_s2>>s_s3>>s_s4;
    if(s_s1==s_s3){
		cout<<"1";
		if(s_s2[0]==s_s4[0]&&s_s2[1]==s_s4[1]){
			cout<<"1";
			if(judge_x(s_s2[2])==judge_x(s_s4[2])){
				cout<<"1";
				if(abs(s_s2[2]-s_s4[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
    else cout<<"0000";
    return 0;
}
