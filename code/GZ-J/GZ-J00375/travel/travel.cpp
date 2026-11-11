//GZ-J00375 黄钜 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string s1[10000],s2[10000],ans[1000];
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<s1.size();i++){
		if((s1[2]+'0')-(s2[2]+'0')==1 || (s1[2]+'0')-(s2[2]+'0')==-1) {
			if((s1[2]<'D'&&s2[2]<'D') || (s1[2]>'C'&&s2[2]>'C')){
				ans[4]='1';
				
			} 
			else ans[4]='0';
			}
			else ans[4]='0';
		if(s1[0]==s2[0] && s1[1]==s2[1]) {
					if((s1[2]<'D' && s2[2]<'D') || (s1[2]>'C' && s2[2]>'C')) ans[3]='1';
					else ans[3]='0';
				}	
		if(s1[0]==s2[0] && s1[1]==s2[1]) {
					ans[2]='1';
		}	
		else {
			ans[2]='0';
			ans[3]='0';
			ans[4]='0';
	}
										
	}	
	if(c1==c2) {
		ans[1]='1';

	}
	else {
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
		ans[4]='0';
	}
	
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
}
