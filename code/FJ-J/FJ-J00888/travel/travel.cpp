#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	string a3="",b3="";
	a3=a3+a2[0];
	a3=a3+a2[1];
	b3=b3+b2[0];
	b3=b3+b2[1];
	if(a3!=b3)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	char a4=a2[2],b4=b2[2];
	if(a4>b4) swap(a4,b4);
	if((a4=='A'&&b4=='B')||(a4=='A'&&b4=='C')||(a4=='B'&&b4=='C')||(a4=='D'&&b4=='F'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((a4=='A'&&b4=='B')||(a4=='B'&&b4=='C')||(a4=='D'&&b4=='F')) cout<<"1";
	else cout<<"0";
	return 0;
}

