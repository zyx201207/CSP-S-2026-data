#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,op="";
	cin>>c1>>s1>>c2>>s2;
	int a=s1[2],b=s2[2];
	if(c1==c2) op+="1";
	else op+="0";
	if(c1==c2&&s1[0]+s1[1]==s2[0]+s2[1]) op+="1";
	else op+="0";
	if((c1==c2&&s1[0]+s1[1]==s2[0]+s2[1])&&(((a+2==b)&&a=="D")||((b+2==a)&&b=="D")||((a+1==b||a+2==b)&&a=="A")||((b+1==a||b+2==a)&&b=="A")||((a+1==b)&&a=="B")||((b+1==a)&&b=="B"))) op+="1";
	else op+="0";
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) op+="1";
	else op+="0";
	cout<<op;
}