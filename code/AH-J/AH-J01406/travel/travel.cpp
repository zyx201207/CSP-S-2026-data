#include<Bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	int c1,c2,p1=0,p2=0,k1=0,k2=0;
	cin>>c1>>s1>>c2>>s2;
	p1=(s1[0]-'0')*10+s1[1]-'0',p2=(s2[0]-'0')*10+s2[1]-'0';
	k1=s1[2]-'A',k2=s2[2]-'A';
	if(k1>k2) swap(k1,k2);
	if(c1==c2) cout<<"1";
	else cout<<"0";
	if(c1==c2&&p1==p2) cout<<"1";
	else cout<<"0";
	if(c1==c2&&p1==p2&&((k1>=0&&k1<=2&&k2>=0&&k2<=2)||(k1>=3&&k1<=5&&k2>=3&&k2<=5))) cout<<"1";
	else cout<<"0";
	if(c1==c2&&p1==p2){
		if((k1>=0&&k1<=2&&k2>=0&&k2<=2&&k2-k1==1)||(k1>=3&&k1<=5&&k2>=3&&k2<=5)) cout<<"1";
		else cout<<"0";
	}
	else cout<<"0";
	return 0;
}
