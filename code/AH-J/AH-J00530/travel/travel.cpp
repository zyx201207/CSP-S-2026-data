#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool o1=0,o2=0,o3=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if((c1[0]==c2[0])&&(c1[1]==c2[1]))
    {
		o1=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(o1&&(s1[0]==s2[0])&&(s1[1]==s2[1]))
	{
		o2=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(o2&&((s1[2]>'C'&&s2[2]>'C')||(s1[2]<'D'&&s2[2]<'D')))
	{
		o3=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	if(o3&&((s1[2]-s2[2]==1||s2[2]-s1[2]==1)||(s1[2]=='F'||s1[2]=='D')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
    return 0;
}    
