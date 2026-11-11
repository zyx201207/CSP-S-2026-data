//GZ-J00579 遵义市新浦新区滨湖中学  安李晨 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans+='1';
	else ans+='0';
	 
	string p1=s1,p2=s2;
	p1.erase(2);
	p2.erase(2);
	if(p1==p2&&ans[0]=='1') ans+='1';
	else ans+='0';
	
	char z1=s1[2],z2=s2[2];
	if((!(z1<='C'&&z2>='D'||z2<='C'&&z1>='D'))&&ans[1]=='1') ans+='1';
	else ans+='0';
	
	if((int(z1-z2==1)||int(z2-z1==1))&&ans[2]=='1') ans+='1';
	else ans+='0';
	
	cout<<ans;
	return 0;
} 
