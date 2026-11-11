#include<bits/stdc++.h>
using namespace std;
/*int read(){
	int nnnnn=0,fffff=1;
	char c=getchar();
	for(;!isdight(c);c=getchar())if(c=='-')fffff=-1;
	for(;isdight(c);c=getchar())nnnnn=nnnnn*10+c-'0';
	return nnnnn*fffff;
}*/
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	bool t3=(s1==s3);
	cout<<t3;
	bool t=t3&&(s2[0]*10+s2[1])==(s4[0]*10+s4[1]);
	bool t2=(t&&(s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D'));
	cout<<t<<t2;
	cout<<((t2&&abs(int(s2[2]-s4[2]))==1)?1:0);
	//cout<<abs(int(s2[2]-s4[2]));
	return 0;
}//nijvenvrfnijvfijnvrfijnrvfnijrfvijnvrfnijvrfjnvrijnrfvijnrfvijnrvnijvnvrfnijvfnfevwkokmdclkmdcsdlkmcs
