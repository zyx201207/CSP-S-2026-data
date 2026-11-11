#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int a=0,b=0,a1=0,b1=0,f1=0;
    for(int i=0;i<=1;i++)
    {
		int t1=c1[i]-'0',t2=c2[i]-'0',t3=s1[i]-'0',t4=s2[i]-'0';
		a=a*10+t1;b=b*10+t2;a1=a1*10+t3;b1=b1*10+t4;
	}
	if(s1[2]<='C')
	{
		if(s2[2]>'C') f1=0;
		else f1=1;
	}
	if(s1[2]>'C')
	{
		if(s2[2]>'C') f1=1;
		else f1=0;
	}
	if(a==b) cout<<1;
	else
	{
		 cout<<"0000";
		 return 0;
	}
	if(a1==b1) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	} 
	if(f1==1) cout<<1;
	else
	{ 
		cout<<"00";
		return 0;
	}
	int k=abs(s2[2]-s1[2]);
	if(k==1) cout<<1;
	else cout<<0;
	return 0;
}
