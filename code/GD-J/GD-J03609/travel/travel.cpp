#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
char t[105],t1[105],t2[105],t3[105];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",t+1,t1+1,t2+1,t3+1);
	if(t[1]==t2[1]&&t[2]==t2[2])
	{
		cout<<1;
		if(t1[1]==t3[1]&&t1[2]==t3[2])
		{
			cout<<1;
			if(((t1[3]=='F'||t1[3]=='D')&&(t3[3]=='A'||t3[3]=='B'||t3[3]=='C'))||((t1[3]=='A'||t1[3]=='B'||t1[3]=='C')&&(t3[3]=='D'||t3[3]=='F')))
	{
		cout<<"00";
	}
	else
	{
		cout<<"1";
		if(abs(t1[3]-t3[3])==1)
		{
			cout<<"1";
		}
		else
		cout<<"0";
	}
		}
		else
		cout<<"000";
	}
	else
	cout<<"0000";
	
	return 0;
}
