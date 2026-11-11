#include<bits/stdc++.h>
using namespace std;
#define int long long
int a1,a2;
string b1,b2;
int ans1,ans2,ans3;
int x,y;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	ans1=bool(a1==a2);
	cout<<ans1;
	if(!ans1)
	{
		cout<<"000";
		return 0;
	}
	ans2=bool(b1[1]==b2[1]);
	cout<<ans2;
	if(!ans2)
	{
		cout<<"00";
		return 0;
	}
	bool f1=(b1[2]<='C'),f2=(b2[2]<='C');
	ans3=bool(f1==f2);
	cout<<ans3;
	if(!ans3)
	{
		cout<<"0";
		return 0;
	}
	x=abs(b1[1]-b2[1]),y=abs(b1[2]-b2[2]);
	if(x+y==1)cout<<1;
	else cout<<0;
	return 0;
}