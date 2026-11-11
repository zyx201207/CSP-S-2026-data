#include<bits/stdc++.h>
using namespace std;
int a[5],b[3];
bool flag=true;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sa,sb,sc,sd;
	cin>>sa>>sb>>sc>>sd;
	a[1]=(sa[0]-'0')*10+(sa[1]-'0');
	a[2]=(sc[0]-'0')*10+(sc[1]-'0');
	if(a[1]==a[2]) cout<<1;
	else 
	{
		flag=false;
		cout<<0;
  }
	b[1]=(sb[0]-'0')*10+(sb[1]-'0');
	b[2]=(sd[0]-'0')*10+(sd[1]-'0');
	if(b[1]==b[2]&&flag) cout<<1;
	else 
	{
		flag=false;
		cout<<0;
  }
  if((flag==true)&&((sb[2]=='D'&&sd[2]=='F')||(sb[2]=='F'&&sd[2]=='D')||(sb[2]=='A'&&sd[2]=='B')||(sb[2]=='B'&&sd[2]=='A')||(sb[2]=='A'&&sd[2]=='C')||(sb[2]=='C'&&sd[2]=='A')||(sb[2]=='B'&&sd[2]=='C')||(sb[2]=='C'&&sd[2]=='B'))) cout<<1;
  else 
  {
		flag=false;
		cout<<0;
  }
  if((flag==true)&&((sb[2]=='D'&&sd[2]=='F')||(sb[2]=='F'&&sd[2]=='D')||(sb[2]=='A'&&sd[2]=='B')||(sb[2]=='B'&&sd[2]=='A')||(sb[2]=='B'&&sd[2]=='C')||(sb[2]=='C'&&sd[2]=='B'))) cout<<1;
  else cout<<0;
	return 0;
}