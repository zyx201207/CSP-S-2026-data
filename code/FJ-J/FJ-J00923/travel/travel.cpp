#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<"1";
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
			cout<<"1";
			int a=1,b=1;
			if(s_1[2]=='A'||s_1[2]=='B'||s_1[2]=='C')a=1;
			else a=0;
			if(s_2[2]=='A'||s_2[2]=='B'||s_2[2]=='C')a=1;
			else a=0;
			if(a==b){
				cout<<"1";
				int d=0,e=0;
				d=int(s_1[2]);
				e=int(s_2[2]);
				if(abs(d-e)==1||(a==0&&b==0)){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
