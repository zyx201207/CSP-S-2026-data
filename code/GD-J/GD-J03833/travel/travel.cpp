#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans="";
void check(){
	if(c1==c2){
		ans+='1';
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ans+='1';
			if((((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')) || ((s1[2]=='D' || s1[2]=='F') )&& (s2[2]=='D' || s2[2]=='F')) && (s1[2]!=s2[2])){
				ans+='1';
				if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && (s2[2]=='A' || s2[2]=='C')) || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')){
					ans+='1';
				}else ans+='0';
			}else{
				ans+="00";
			}
		}else{
		ans+="000";
		} 
	}
	else{
		ans+="0000";
	} 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	check(); 
	cout<<ans;
	return 0;
} 
