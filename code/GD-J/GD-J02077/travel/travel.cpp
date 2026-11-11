#include <bits/stdc++.h>
using namespace std;
#define ll long long
string ca,sa,cb,sb;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		ll na=10*(sa[0]-'0')+(sa[1]-'0'),xa=sa[2]-'0';
		ll nb=10*(sb[0]-'0')+(sb[1]-'0'),xb=sb[2]-'0';
		if(na==nb){
			if((xa>=4&&xb>=4)||(xa<=3&&xb<=3)){
				if(xa-xb==1||xb-xa==1) cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<"1000";
	}else cout<<"0000";
	return 0;
}
