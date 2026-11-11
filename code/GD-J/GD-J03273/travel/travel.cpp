#include<bits/stdc++.h>
using namespace std;

int main(){
	int c1,c2,c,b;
    int a[4]={0,0,0,0};
    string s1,s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a[0]=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a[0]==1) a[1]=1;
	if(s1[2]<='C'&&s2[2]<='C'&&a[1]==1) a[2]=1;
	c=s1[2]-'0';
	b=s2[2]-'0';
	if(s1[2]=='C'&&s2[2]=='D') a[3]=2;
	if(s1[2]=='D'&&s2[2]=='C') a[3]=2;
	if(abs(c-b)==1&&a[3]!=2&&a[2]==1) a[3]=1;
	if(a[3]==2) a[3]=0;
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;

}


