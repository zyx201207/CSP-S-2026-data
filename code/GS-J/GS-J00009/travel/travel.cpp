#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		if(s1[0]*10+s1[1]==s2[0]*10+s2[1]){
			cout<<'1';
			if((s1[2]-'A'+1<=3 && s2[2]-'A'+1<=3)||(s1[2]-'A'+1>3 && s2[2]-'A'+1>3)){
				cout<<'1';
				if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}
			else{
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
