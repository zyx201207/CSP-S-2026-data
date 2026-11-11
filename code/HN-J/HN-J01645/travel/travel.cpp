#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int an[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int sf=0;
	if(s1==s3&&sf!=1)cout<<1;
	else {
		cout<<0;
		sf=1;
	}
	if((s2[0]-'0')*10+s2[1]-'0'==(s4[0]-'0')*10+s4[1]-'0'&&sf!=1)cout<<1;
	else {
		cout<<0;
		sf=1;
	}
	an[s2[2]]=1,an[s4[2]]=1;
	if(((an['D']!=1||an['C']!=1)&&abs(s2[2]-s4[2])==1||(abs(s2[2]-s4[2])==2&&(s2[2]!='D'||s4[2]!='D')))&&sf!=1)cout<<1;
	else {
		cout<<0;
		sf=1;
	}
	if(((an['D']!=1||an['C']!=1)&&abs(s2[2]-s4[2])==1||(an['D']==1&&an['F']==1))&&sf!=1)cout<<1;
	else {
		cout<<0;
		sf=1;
	}
	return 0;
}

