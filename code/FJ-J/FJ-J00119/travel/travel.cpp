#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int flag1,flag2,flag3,flag4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)	flag1=1;
	if(b[0]==d[0]&&b[1]==d[1]&&flag1==1)flag2=1;
	if(((b[2]<'D'&&d[2]<'D')||(b[2]>'C'&&d[2]>'C'))&&flag1==1&&flag2==1)flag3=1;
	if(flag1==1&&flag2==1&&flag3==1&&((b[2]+1==d[2])||(d[2]+1==b[2])))flag4=1;
	if(flag1==1&&flag2==1&&flag3==1&&(b[2]=='D'||d[2]=='D')&&(b[2]=='F'||d[2]=='F'))
	{
		if(b[2]+2==d[2]||d[2]+2==b[2])flag4=1;
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
