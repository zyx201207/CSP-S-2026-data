#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a;
int s3,s4,s5,s6;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s3=(s1[0]-'0')*10+(s1[1]-'0');
		s4=(s2[0]-'0')*10+(s2[1]-'0');
		if(s3==s4){
			s5=s1[2]-'A';
			s6=s2[2]-'A';
			if(s1[2]=='F') s5-=1;
			if(s2[2]=='F') s6-=1;
			if((s5<=2&&s6<=2)||(s5>=3&&s6>=3)){
				if(s5+1==s6||s5-1==s6){
					a="1111";
				}
				else{
					a="1110";
				}
			}
			else{
				a="1100";
			}
		}
		else{
			a="1000";
		}
	}
	else{
		a="0000";
	}
	cout<<a;
	return 0;
}
