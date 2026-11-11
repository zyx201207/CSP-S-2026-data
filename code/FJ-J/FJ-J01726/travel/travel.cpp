#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool x1,x2,x3,x4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)x1=1;
	else x1=0;
	if(x1&&s1[0]==s2[0]&&s1[1]==s2[1])x2=1;
	else x2=0;
	if(x2&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))x3=1;
	else x3=0;
	if(x1&&x2&&x3&&abs(s1[2]-s2[2])==1)x4=1;
	else x4=0;
	cout<<x1<<x2<<x3<<x4;
}
