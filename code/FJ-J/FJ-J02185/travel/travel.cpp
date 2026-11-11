#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;int a[4];
	cin>>c>>s>>cc>>ss;
	if(c==cc) a[1]=1;
	else a[1]=0;
	if(s[0]==ss[0]&&s[1]==ss[1]&&a[1]==1) a[2]=1;
	else a[2]=0;
	if(a[1]==1&&a[2]==1)
	 if((s[2]=='A'&&(ss[2]=='B'||ss[2]=='C'))||(s[2]=='B'&&(ss[2]=='A'||ss[2]=='C'))||(s[2]=='C'&&(ss[2]=='A'||ss[2]=='B'))||(s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D'))
	  a[3]=1;
	 else a[3]=0;
	else a[3]=0;
	if(abs(s[2]-ss[2])==1&&a[1]==1&&a[2]==1&&a[3]==1)
	 a[4]=1;
	else a[4]=0;
	for(int i=1;i<=4;i++)
		cout<<a[i];
	return 0;
}