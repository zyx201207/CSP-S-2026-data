#include<bits/stdc++.h>
using namespace std;
int x,xx,y,yy,n,m;
char a,b;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>a>>xx>>yy>>b;
	n=a-'A'+1;m=b-'A'+1;
	if(x==xx)cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(y==yy)cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if((n<=3&&m<=3)||(n>3&&m>3))cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(n-m)==1)cout<<"1";
	else cout<<"0";
	return 0; 
}
