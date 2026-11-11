#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int rc,rp,rw,xc,xp,xw;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	rc=(c1[0]-'0')*10+c1[1]-'0';
	rp=(s1[0]-'0')*10+s1[1]-'0';
	rw=s1[2]-'A'+1;
	xc=(c2[0]-'0')*10+c2[1]-'0';
	xp=(s2[0]-'0')*10+s2[1]-'0';
	xw=s2[2]-'A'+1;
	if(rc==xc){
		if(rp==xp){
			if((rw<=3&&xw<=3)||(rw>3&&xw>3)){
				if(rw==xw+1||rw==xw-1) ans="1111";
				else ans="1110";
			}
			else ans="1100";
		}
		else ans="1000";
	}
	else ans="0000";
	cout<<ans;
	return 0;
}
