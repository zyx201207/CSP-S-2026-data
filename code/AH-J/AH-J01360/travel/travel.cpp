#include<bits/stdc++.h>
using namespace std;
string x,y;
int a,b;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>x>>b>>y;
if(a==b)
{
	cout<<1;
}
else 
{
	cout<<"0000";
	return 0;
}
if(x[1]==y[1]){
 cout<<1;
	if(char(x[2])<=67&&char(y[2])<=67||char(x[2])>67&&char(y[2])>67)
	{
		cout<<1;
		if(char(x[2])-char(y[2])==1||char(x[2])-char(y[2])==-1) cout<<1;
		else cout<<0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
}
else
{
	cout<<"000";
	return 0;
}
return 0;
}

