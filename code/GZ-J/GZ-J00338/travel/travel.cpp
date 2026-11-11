//GZ-J00338 贵阳市第三实验中学 张普博
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
string lt="ABC",rt="DF";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans+='1';
	else{
		ans+="0000";
		cout<<ans;
		return 0; 
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) ans+='1';
	else{
		ans+="000";
		cout<<ans;
		return 0;
	}
	if(lt.find(s1[2])!=string::npos&&lt.find(s2[2])!=string::npos){
		ans+='1';
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) ans+='1';
		else ans+='0';
	}
	else if(rt.find(s1[2])!=string::npos&&rt.find(s2[2])!=string::npos){
		ans+="11";
	}
	else ans+="00";
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
