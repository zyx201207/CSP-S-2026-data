#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,ss,t,tt,ans;
	cin>>s>>ss>>t>>tt;
	if(s==t){
		ans=ans+'1';
		if(ss[0]==tt[0]&&ss[1]==tt[1]){
			ans=ans+'1';
			if((ss[2]<='C'&&tt[2]<='C')||(ss[2]>'C'&&tt[2]>'C')){
				ans=ans+'1';
				if(max(ss[2],tt[2])-min(ss[2],tt[2])==1){
					ans+='1';
				}
				else ans=ans+'0';
			}
			else{
				ans=ans+"00";
			}
		}
		else{
			ans=ans+"000";
		}
	}
	else{
		ans=ans+"0000";
	}
	cout<<ans;
	return 0;
} 
