#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx) cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(((sr[0]-'0')*10+(sr[1]-'0'))==((sx[0]-'0')*10+(sx[1]-'0'))) cout<<1;
	else 
	{
		cout<<"1000";
		return 0;
	}
	if(sr[2]!='D'&&sr[2]!='F'&&sx[2]!='D'&&sx[2]!='F') cout<<1;
	else if(sr[2]!='A'&&sr[2]!='B'&&sr[2]!='C'&&sx[2]!='A'&&sx[2]!='B'&&sx[2]!='C') cout<<1;
	else 
	{
		cout<<"1100";
		return 0;
	}
	if(abs(sr[2]-sx[2])==1) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
