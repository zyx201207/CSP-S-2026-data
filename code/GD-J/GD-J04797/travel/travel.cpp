#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string ans="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			char S1=s1[2];
			char S2=s2[2];
			if((S1=='A'||S1=='B'||S1=='C'&&S2=='A'||S2=='B'||S2=='C')||(S1=='D'||S1=='E'&&S2=='D'||S2=='E')){
				ans+="1";
				if(abs(S1-S2)==1){
					ans+="1";
				}
				else{
					ans+="0";
				}
			}
			else{
				ans+="00";
			}
		}
		else{
			ans+="000";
		}
	}
	else{
		ans+="0000";
	}
	cout<<ans;
	return 0;
}
