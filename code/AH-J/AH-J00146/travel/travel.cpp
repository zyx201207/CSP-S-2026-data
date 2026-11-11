#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c1,c2;
	bool f;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	f=(c1==c2);
	cout<<f;
	f=(f&&s1[0]+s1[1]==s2[0]+s2[1]);
	cout<<f;
	f=(f&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'));
	cout<<f;
	if(f&&s1[2]>='D'&&s2[2]>='D')
	{
		cout<<1;
	}
	else
	{
		if(!f)
		{
			cout<<0;
		}
		else if(s1[2]+1==s2[2]||s2[2]+1==s1[2])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
}
