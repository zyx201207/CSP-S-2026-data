//GZ-J00181 贵阳市第一中学 张梁予 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans1,ans2,ans3,ans4,ans;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ans1=ans2=ans3=ans4="0";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans1="1";
	if((s1[0]==s2[0] && s1[1]==s2[1]) && ans1=="1") ans2="1";
	if(((s1[2]<='C' && s2[2]<='C')||(s1[2]>='D' && s2[2]>='D')) && ans2=="1") ans3="1";
	if((abs(s1[2]-s2[2])==1) && ans3=="1") ans4="1";
	ans=ans1+ans2+ans3+ans4;
	cout<<ans;
	return 0;
}
