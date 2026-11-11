#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
string s,t;
int n,m;

void cheak()
{
	char S = s[2],T = t[2];
	if(S<='C' && T>='D')
	{
		cout<<"1100";
	}
	else if(S>='D' && T<='C')
	{
		cout<<"1100";
	}
	else if(S<='C' && T<='C')
	{
		if(abs((int)(S-T)) == 1)
		{
			cout<<"1111";
		}
		else
		{
			cout<<"1110";
		}
	}
	else if(S>='D' && T>='D') cout<<"1111";
	else cout<<"1110";
	return ;
}

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>s>>m>>t;
	if(n != m)
	{
		cout<<"0000";
	}
	else if(s[0] != t[0])
	{
		cout<<"1000";
	}
	else if(s[1] != t[1])
	{
		cout<<"1000";
	}
	else
	{
		cheak();
	}
	
	
	return 0;
}
