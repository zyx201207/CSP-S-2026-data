#include<bits/stdc++.h>
using namespace std;
string a1,a2;
string b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2) cout<<'1';
	else cout<<'0';
	if(b1[1]==b2[1] and a1==a2) cout<<'1';
	else cout<<'0';
	if(b1[1]==b2[1] and a1==a2)
	{
		if((b1[2]<='C' and b2[2]<='C') or (b1[2]>='D' and b2[2]>='D'))
		{
			cout<<'1';
			if(b1[2]+1==b2[2] or b2[2]-1==b2[2]) cout<<'1';
			else cout<<'0';
		}
		else cout<<'0'<<'0';
	}
	else cout<<'0'<<'0';
	return 0;
 } 
