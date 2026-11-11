#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string c_1,s_1,c_2,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<"1";
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
			cout<<"1";
			int ps=-1,ps1=-1;
			if(s_1[2]<='C'){
				ps=1;
			}else ps=2;
			if(s_2[2]<='C'){
				ps1=1;
			}else ps1=2;
			if(ps1==ps){
				cout<<"1";
				int num1=0,num2=0;
				num1=s_1[2]-'A'+1;
				num2=s_2[2]-'A'+1;
				if(abs(num1-num2)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
