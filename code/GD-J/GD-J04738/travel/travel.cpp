#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a,b;
	cin>>c1>>s1>>c2>>s2;
	a=s1[2]-'A'+1;
	b=s2[2]-'A'+1;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if((1<=a&&a<=3&&1<=b&&b<=3)||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
				cout<<"1";
				if(abs(a-b)==1||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
