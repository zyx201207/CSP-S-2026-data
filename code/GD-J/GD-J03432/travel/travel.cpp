#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
string a1,a2,b1,b2;
string ans="";
int p1,z1,p2,z2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	p1=(b1[0]-'0')*10+b1[1]-'0',p2=(b2[0]-'0')*10+b2[1]-'0';
	z1=b1[2],z2=b2[2];
	if(a1==a2){
		ans+="1";
		if(p1==p2){
			ans+="1";
			if((z1<='C'&&z2<='C')||(z1>'C'&&z2>'C')){
				ans+="1";
				if(abs(z1-z2)==1) ans+="1";
				else ans+="0";
			}else ans+="00";
		}else ans+="000";
	}else ans="0000";
	cout<<ans;
	return 0;
}
