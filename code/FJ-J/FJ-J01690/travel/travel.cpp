#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,t1,t2,ans="";
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1){
		ans+='1';
		if(s2[0]==t2[0]&&s2[1]==t2[1]){
			ans+='1';
			if((s2[2]<='C'&&t2[2]<='C')){
				ans+='1';
				if(abs(s2[2]-t2[2])==1)ans+='1';
				else ans+='0';
			}
			else if(s2[2]>='D'&&t2[2]>='D')ans+="11";
			else ans+="00";
		}
		else ans+="000";
	}
	else ans+="0000";
	cout<<ans;
	return 0;
}
