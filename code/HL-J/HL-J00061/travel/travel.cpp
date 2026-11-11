#include<bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz;
char ans[7];
int len;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc) ans[len]='1';
	else ans[len]='0';
	len++;
	string rzz=rz,xzz=xz;
	rz.erase(2,1);
	xz.erase(2,1);
	if(rz==xz) ans[len]='1';
	else ans[len]='0';
	len++;
	rzz.erase(0,2);
	xzz.erase(0,2);
	if(rzz=="A"||rzz=="B"||rzz=="C")
	{
		if(xzz=="A"||xzz=="B"||xzz=="C") ans[len]='1';
		else ans[len]='0';
	}
	else if(rzz=="D"||rzz=="F")
	{
		if(xzz=="D"||xzz=="F") ans[len]='1';
		else ans[len]='0';
	}
	len++;
	if(rzz=="A"&&xzz=="B"||rzz=="B"&&xzz=="C"||rzz=="D"&&xzz=="F"||xzz=="A"&&rzz=="B"||xzz=="B"&&rzz=="C"||xzz=="D"&&rzz=="F") ans[len]='1';
	else ans[len]='0';
	for(int i=0;i<=len;i++)
	{
		cout<<ans[i];
	}
	return 0;
}