#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
   	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,o; 
	cin>>c1>>s1>>c2>>s2;
	int p=4;
	while(p--){
	if(c1==c2){
	o+="1";
	}else o+="0000";break;
	if((s1[0]==s2[0]&&s1[1]==s2[1])){
		o+="1";
	}else o+="000";break;
	if((s1[2]>71&&s2[2]>71)||s1[2]<=71||s2[2]<=71){
		o+="1";
	}else o+="00";break;
	if((s1[2]==s2[2]+1&&s1[2]!=72)||(s2[2]==s1[2]+1)&&(s2[2]!=72)){
			o+="1";
	}else o+="0";break;
}
	cout<<o;
	return 0;
}
