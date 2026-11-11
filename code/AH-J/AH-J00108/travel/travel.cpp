#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans="";
int zt1,zt2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) ans="0000";
	else{
		ans+='1';
		if(s1[0]!=s2[0] || s1[1]!=s2[1]) ans+="000";
		else{
			ans+='1';
			zt1=((s1[2]>='A' && s1[2]<='C') ? 0 : 1);
			zt2=((s2[2]>='A' && s2[2]<='C') ? 0 : 1);
			if(zt1!=zt2) ans+="00";
			else{
				ans+='1';
				if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F')) ans+='1';
				else if((s1[2]=='B' && s2[2]=='A') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='F' && s2[2]=='D')) ans+='1';
				else ans+='0';
			}
		}
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
