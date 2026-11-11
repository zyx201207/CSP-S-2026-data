#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string ans="";
	cin>>c1>>s1>>c2>>s2;
	int car1=(c1[0]-'0')*10+c1[1]-'0';
	int car2=(c2[0]-'0')*10+c2[1]-'0';
	if(car1==car2) ans=ans+'1';
	else ans=ans+'0';
	int l1=(s1[0]-'0')*10+s1[1]-'0';
	int l2=(s2[0]-'0')*10+s2[1]-'0';
	if(ans[0]=='1'&&l1==l2) ans=ans+'1';
	else ans=ans+'0';
	int seat1=s1[2]-'A'+1;
	int seat2=s2[2]-'A'+1;
	if(ans[1]=='1'&&((seat1<=3&&seat2<=3)||(seat1>=4&&seat2>=4)) ) ans+='1';
	else ans+='0';
	if(ans[2]=='1'&&abs(seat1-seat2)==1) ans=ans+'1';
	else ans=ans+'0';
	cout<<ans;
	return 0;
}
