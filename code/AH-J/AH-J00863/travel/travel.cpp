#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1])
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"1000";
		return 0;
	}
	int t1=s1[2]-'A',t2=s2[2]-'A';
	if((t1<=2&&t2>=3)||(t1>=3&&t2<=2))
	{
		cout<<"1100";
		return 0;
	}
	if(t2-t1!=1&&t1-t2!=1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
