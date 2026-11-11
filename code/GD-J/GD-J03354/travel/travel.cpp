#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a=int(s1[2]-'A'+1);
			b=int(s2[2]-'A'+1);
			if(a<=3&&b<=3){
				if(abs(a-b)==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
				
			}else if(a>=4&&b>=4){
				if(abs(a-b)==2){
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
	return 0;
} 
