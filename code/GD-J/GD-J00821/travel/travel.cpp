#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans+="1";
		if((b[0]-'0')-(d[0]-'0')==0&&(b[1]-'0')-(d[1]-'0')==0){
			ans+="1";
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')){
				ans+="1";
				if((b[2]-'0')-(d[2]-'0')==-1||(b[2]-'0')-(d[2]-'0')==1){
					ans+="1";
				}else{
					ans+="0";
				}
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		ans="0000";
	}
	cout<<ans;
	return 0;
}
