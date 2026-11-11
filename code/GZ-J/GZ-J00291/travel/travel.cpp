//GZ-J00291，石鑫，凯里市第十三中学 
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string c1,s1,c2,s2;
	string ans="0000";
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<'\n'<<s1<<' '<<c2<<' '<<'\n';
	
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		ans[0]='1';
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ans[1]='1';
			if((
				(('A'==s1[2])||(s1[2]=='C')||(s1[2]=='B'))
				 && (('A'==s2[2])||(s2[2]=='C')||(s2[2]=='B'))
			 )
			|| (
				(('D'==s1[2])||(s1[2]=='F'))
				 && (('D'==s2[2])||(s2[2]=='F'))
			 )){
				ans[2]='1';
				if((s1[2]-s2[2]==1)||(s1[2]-s2[2]==-1)){
					ans[3]='1';
				}
			}
		}
	}
	//string opt;
	//opt=char(ans[0]+'0')+char(ans[1]+'0')+char(ans[2]+'0')+char(ans[3]+'0');
	cout<<ans;
	return 0;
}
