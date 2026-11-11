#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int tmp=0;
	cin>>c1>>s1>>c2>>s2;
	tmp=s1[2]-s2[2];
	bool flag1=0,flag2=0,flag3=0,flag4=0;
	if(c1==c2)flag1=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag1==1)flag2=1;
	if(((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))&&flag2==1)flag3=1;
	if(abs(tmp)==1&&flag3==1)flag4=1;
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
