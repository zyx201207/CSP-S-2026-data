#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool b1=(c1==c2);
	bool b2=(b1&&(s1[0]==s2[0]&&s1[1]==s2[1]));
	bool b3;
	if(b1&&b2&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')))
		b3=1;
	else
		b3=0;
	bool b4;
	if(b1&&b2&&b3&&(abs(s1[2]-s2[2])==1))
		b4=1;
	else
		b4=0;
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
