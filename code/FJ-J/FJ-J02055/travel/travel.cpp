#include<bits/stdc++.h>
using namespace std;
string ans="";
string r1,r2;
string x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2;
	cin>>x1>>x2;
	if(r1==x1){
		ans=ans+"1";
		if(r2[0]==x2[0]&&r2[1]==x2[1]){
			ans=ans+"1";
			if((r2[2]<'D'&&x2[2]<'D')||(r2[2]>'C'&&x2[2]>'C')){
				ans=ans+"1";
				if(abs(r2[2]-x2[2])==1){
					ans=ans+"1";
				}else{
					ans=ans+"0";
				}
			}else{
				ans=ans+"00";
			}
		}else{
			ans=ans+"000";
		}
	}else{
		ans=ans+"0000";
	}
	cout<<ans;
	return 0;
}
