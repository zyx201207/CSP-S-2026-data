#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char c3,s3;
	cin>>c1>>c2>>c3>>s1>>s2>>s3;
	if(c1==s1) 
	{
	cout<<1;
	if(c2==s2) 
	{
	cout<<1;
	if(((c3=='A'||c3=='B'||c3=='C')&&(s3=='A'||s3=='B'||s3=='C'))||((c3=='D'||c3=='F')&&(s3=='D'||s3=='F')))
	{
	cout<<1;	
	if(((c3=='C'||c3=='D')&&(s3=='C'||s3=='D'))||((c3=='A'||c3=='C')&&(s3=='A'||s3=='C')))
	{
 	cout<<0;
    }else cout<<1;
    }else cout<<"00";
    }else cout<<"000";
    }else cout<<"0000";
	return 0;
}
	
