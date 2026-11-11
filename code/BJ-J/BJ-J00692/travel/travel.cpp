#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	string tmp1="";
	tmp1+=a2[0];
	tmp1+=a2[1];
	string tmp2="";
	tmp2+=b2[0];
	tmp2+=b2[1];
	if(tmp1==tmp2) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	int t1=(a2[2]=='A' || a2[2]=='B' || a2[2]=='C');
	int t2=(b2[2]=='A' || b2[2]=='B' || b2[2]=='C');
	if(t1==t2) cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	char a=a2[2];
	char b=b2[2];
	if(a<b) swap(a,b);
	if(a=='F' && b=='D') cout<<"1";
	else if(a=='C' && b=='B') cout<<"1";
	else if(a=='B' && b=='A') cout<<"1";
	else cout<<"0";
	return 0;
}
