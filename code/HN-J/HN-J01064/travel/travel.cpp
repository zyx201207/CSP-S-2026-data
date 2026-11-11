#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2,ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){		
		ans[0]='1';
		if(s_1[0]==s_2[0] && s_1[1]==s_2[1]){
			ans[1]='1';
			if(s_1[2]>=65&&s_1[2]<=67 && s_2[2]>=65&&s_2[2]<=67 ||
			 s_1[2]>=68&&s_1[2]<=70 && s_2[2]>=68 && s_2[2]<=70){
			 	ans[2]='1';
			 	if(abs(s_1[2]-s_2[2])==1 || s_1[2]=='D'&&s_2[2]=='F'||s_1[2]=='D'&&s_2[2]=='F'){
			 		ans[3]='1';
				 }
			}
		}
		
	}
	cout<<ans;
	return 0;
}
