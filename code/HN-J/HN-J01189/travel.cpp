#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1==c2){
		ans+="1";
	}else{
		ans+="0";
	}
	int x=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		ans+="1";
		x=1;
	}else{
		ans+="0";
	}
	int y=0;
	if(x==1){
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
			ans+="1";
			y=1;
		}else{
			ans+="0";
		}	
	}else{
		ans+="0";
	}
	if(y==0){
		ans+="0";
	}else{
		if(abs(s1[2]-s2[2])==1){
			ans+="1";
		}else{
			ans+="0";
		}
	}
	return 0;
}
