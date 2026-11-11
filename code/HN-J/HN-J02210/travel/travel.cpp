#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	
	 if(b[0]==d[0]&&b[1]==d[1])cout<<1;
	 else 
	 {
	 	cout<<"000";
	 	return 0;
	 }
	 
	 int cnt=0;
	 if(b[0]==d[0]&&b[1]==d[1])
	 {
	 	if(b[2]=='D'||b[2]=='F')cnt++;
	 	if(d[2]=='D'||d[2]=='F')cnt++;
	 	if(cnt==2||cnt==0)cout<<1;
	 	else cout<<0;
	 }
	 else 
	 {
	 	cout<<"00";
	 	return 0;
	 }
	 
	if(cnt==2)cout<<1;
	else
	{
		if(b[2]=='B'||d[2]=='B')cout<<1;
		else cout<<0;
	 } 
	return 0;
 } 
