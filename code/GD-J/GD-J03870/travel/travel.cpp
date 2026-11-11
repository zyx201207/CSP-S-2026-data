#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool l[128];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	l['A']=1,l['B']=1,l['C']=1;
	cin>>c1>>s1>>c2>>s2;
	string ans;
	if(c1==c2) ans+='1';
	else ans+='0';
	if(ans[0]=='1'&&s1[0]==s2[0]&&s1[1]==s2[1]) ans+='1';
	else ans+='0';
	if(ans[1]=='1'&&l[s1[2]]==l[s2[2]]){
		ans+='1';
	}else ans+='0';
	if(ans[2]=='1'&&abs(s1[2]-s2[2])==1)ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
} 
