#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,cnt=" ";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cnt+='1';
	else cnt+='0';
	if(s1[0]==s1[0]&&s1[1]==s2[1]){
		cnt+='1';
		if ((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
			cnt+='1';
			if (abs(s1[2]-s2[2]==1))cnt+='1';
			else cnt+='0';
		}
		else cnt+="00";
	}
	else cnt+="000";
	
	cout<<cnt;
	
	return 0;
}
