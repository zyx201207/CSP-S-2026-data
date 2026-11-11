#include <bits/stdc++.h>
using namespace std;
string ans="";
string c1, s1, c2, s2;
string t1="";
string t2="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+='1';
		t1+=s1[0];
		t1+=s1[1];
		t2+=s2[0];
		t2+=s2[1];
		if(t1==t2){
			ans+='1';
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s1[2]>='D'&&s1[2]<='F'){
				ans+='1';
				if(s1[2]>='D'&&s1[2]<='F'&&s1[2]>='D'&&s1[2]<='F'&&abs(s1[2]-s2[2])==2) ans+='1';
				else if(abs(s1[2]-s2[2])==1) ans+='1';
				else ans+="0";
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans="0000";
	cout<<ans;
	return 0;
}

