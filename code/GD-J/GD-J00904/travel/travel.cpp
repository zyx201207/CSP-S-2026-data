#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N  = 1e5 + 5;
string c1,s1,c2,s2;
bool tc(char a)
{
	return (a >= 'A' && a <= 'C');
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	int ppp1 = (s1[1]-'a')+(s1[0]-'a')*10;
	int ppp2 = (s2[1]-'a')+(s2[0]-'a')*10;
	if(c1!=c2)//check
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(ppp1 != ppp2)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(tc(s1[2])!=tc(s2[2]))
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(s1[2]-s2[2])>1)
	{
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
}

