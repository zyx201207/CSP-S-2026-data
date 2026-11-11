//GZ-J00192ÕÅ½ÜÈð 
#include<bits/stdc++.h>
using namespace std;
char s1[8],s2[8];int c1,c2;bool b1,b2,b3,b4;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='D')s1[2]='E';
	if(s2[2]=='D')s2[2]='E';
	b1=c1==c2,b2=(s1[0]==s2[0]&&s1[1]==s2[1])&&b1;b3=!(s1[2]<'D'^s2[2]<'D')&&b2,b4=abs(s1[2]-s2[2])==1&&b2;
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
