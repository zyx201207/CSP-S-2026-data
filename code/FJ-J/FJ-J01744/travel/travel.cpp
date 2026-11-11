#include<bits/stdc++.h>
using namespace std;
char a[32423],b[32323],a1[43242],b1[32423];
int s[32131];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++)
		cin>>a[i];
	for(int i=1;i<=3;i++)
		cin>>b[i];
	for(int i=1;i<=2;i++)
		cin>>a1[i];
	for(int i=1;i<=3;i++)
		cin>>b1[i];
	if(a[1]==a1[1]&&a[2]==a1[2]) s[1]=1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[1]==b1[1]&&b[2]==b1[2]) s[2]=1;
	else {
		for(int i=1;i<=4;i++) cout<<s[i];
		return 0;
	}
	if(b[3]=='A'||b[3]=='B'||b[3]=='C'&&b1[3]=='A'||b1[3]=='B'||b1[3]=='C') s[3]=1;
	if(s[3]!=1&&b[3]=='D'||b[3]=='F'&&b1[3]=='D'||b1[3]=='F') s[3]=1;
	if(s[3]==0) {
		for(int i=1;i<=4;i++) cout<<s[i];
		return 0;
	}
	if(b[3]=='A'&&b1[3]=='B'||b[3]=='B'&&b1[3]=='A'||b[3]=='B'&&b1[3]=='C'||b[3]=='C'&&b1[3]=='B'||b[3]=='D'&&b1[3]=='F'||b[3]=='F'&&b1[3]=='D')
	{
		s[4]=1;
		for(int i=1;i<=4;i++) cout<<s[i];
		return 0;
	}
	else{
		cout<<1110;
		return 0;
	}
}
