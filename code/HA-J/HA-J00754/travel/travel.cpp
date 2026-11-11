#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ans;
int a1,a2,a3,b1,b2,b3,k1,k2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	a1=(s1[0]-'0')*10+(s1[1]-'0');
	b1=(s3[0]-'0')*10+(s3[1]-'0');
	a2=(s2[0]-'0')*10+(s2[1]-'0');
	b2=(s4[0]-'0')*10+(s4[1]-'0');
	a3=s2[2]-'A'+1;
	b3=s4[2]-'A'+1;
	if(a3==6) a3--;
	if(b3==6) a3--;
	if(a3==1||a3==2||a3==3) k1=1;
	else k1=2;
	if(b3==1||b3==2||b3==3) k2=1;
	else k2=2;
	if(a1==b1) ans+='1';
	else ans+='0';
	if(a1==b1&&a2==b2) ans+='1';
	else ans+='0';
	if(a1==b1&&a2==b2&&k1==k2) ans+='1';
	else ans+='0';
	if(a1==b1&&a2==b2&&k1==k2&&abs(a3-b3)==1) ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
