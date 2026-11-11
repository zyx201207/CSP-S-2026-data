#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int sum=(s3[0]-'0')*10+(s4[1]-'0');
	int cnt=(s3[0]-'0')*10+(s4[1]-'0');
	if(s1!=s3)
	{
		cout<<"0000";
		return 0;
	}
    if((s3[0]-'0')*10+(s4[1]-'0')!=(s3[0]-'0')*10+(s4[1]-'0'))
	{
		cout<<"1000";
		return 0;	
	}
	if((cnt<3 && sum>=3) || (sum<3 && cnt>=3))
	{
		cout<<"1100";
		return 0;
	}
	if((s3[2]-s4[2])+10==9 || (s3[2]-s4[2])+10==11)
	{
		cout<<"1111";
		return 0;
	}
	else
	{
		cout<<"1110";
		return 0;
	}
	return 0;
}

