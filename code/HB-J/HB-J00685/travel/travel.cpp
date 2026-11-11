#include<bits/stdc++.h>
using namespace std;
string ans="";
char s1[5],s2[5],a1[5],a2[5];
int cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>a1>>s2>>a2;
	
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"0000";
		return 0;
	}
	else{
		ans+="1";
		if(a1[0] == a2[0]&&a1[1] == a2[1]){
			ans+="1";
			if(((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'))||((a1[2]=='D'||a1[2]=='F')&&(a2[2]=='D'||a1[2]=='F'))){
				ans+="1";
				if(abs(a1[2]-a2[2])==1) ans+="1";
			}
			
		}
	}
	for(int i=0;i<4;i++){
		if(ans[i]=='1') cout<<1;
		else cout<<0;
	}
	return 0;
}
