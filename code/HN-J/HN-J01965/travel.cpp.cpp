#include<bits/stdc++.h> 
using namespace std;
#define int long long
signed main(){
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int s2a=0,s4a=0;
	if(s1==s3)
	{
		cout<<"1";
	}
	else if(s1!=s3)
	{
		cout<<"0000";
		return 0;
	}
	s2a=s2[0]*10+s2[1];
	s4a=s4[0]*10+s4[1];
	if(s2a==s4a)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	int x=s2[2],y=s4[2];
	if((x<68&&y<68)||(x>=68&&y>=68)) 
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(x-y==1||y-x==1)
	{
		cout<<"1";
		return 0;
	}
	else cout<<"0";
    return 0;
}
