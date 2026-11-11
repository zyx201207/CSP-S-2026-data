#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1])
		ans+='1',f=true;
	else
		ans+='0',f=false;
	if(s1[1]==s2[1]&&f==true){
		ans+='1';
		f=true;
	}
	else
		ans+='0',f=false;
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&f==true)
		ans+='1';
	else
		ans+='0',f=false;
	if((abs((int)(s1[2])-(int)(s2[2]))==1)&&f==true)
		ans+='1';
	else
		ans+='0';
	cout<<ans;
}
