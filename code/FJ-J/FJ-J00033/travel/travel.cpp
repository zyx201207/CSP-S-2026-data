#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(abs(s2[2]-s1[2])==1&&((s1[2]!='C'&&s2[2]!='D')&&(s2[2]!='C'&&s1[2]!='D'))){
				cout<<"1111";
				return 0;
			}
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='E'))||((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='E'))){
				cout<<"1100";
			}
			else{
				cout<<"1110";
			}
		}
		else{
			cout<<"1000";
		}
	}
	return 0;
}
//Trick||Treat!

