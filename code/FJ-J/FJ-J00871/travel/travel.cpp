#include<bits/stdc++.h>
using namespace std;

string c_1,s_1,c_2,s_2,ans;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		ans+='1';
		if(s_1[0]==s_2[0] && s_1[1]==s_2[1]){
			ans+='1';
			if((s_1[2]<='C' && s_2[2]<='C') || (s_1[2]>'C' && s_2[2]>'C')){
				ans+='1';
				if(s_1[2]<='C' && (s_1[2]+1==s_2[2] || s_1[2]-1==s_2[2])){
					ans+='1';
				}else if(s_1[2]>'C' && (s_1[2]+2==s_2[2] || s_1[2]-2==s_2[2])){
					ans+='1';
				}else{
					ans+='0';
				}
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		ans+="0000";
	}
	cout<<ans;
	return 0;
}
