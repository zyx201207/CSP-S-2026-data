#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
char ans[4];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ans[1]='1';
			if(s1[2]!='A' && s1[2]!='B' && s1[2]!='C' && s2[2]!='A' && s2[2]!='B' && s2[2]!='C' || s1[2]!='E' && s1[2]!='D' && s2[2]!='E' && s2[2]!='D'){
				ans[2]='1';
				if(abs(int(s1[2]-s2[2]))!=1 || s1[2]=='D' && s2[2]=='C' || s1[2]=='C' && s2[2]=='D'){
					ans[3]='0';
				}
				else ans[3]='1';
			}
			else{
				ans[2]='0';
				ans[3]='0';
			}
		}
		else{
			ans[1]='0';
			ans[2]='0';
			ans[3]='0';
		}
	}
	else{
		ans[0]='0';
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
	} 
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
