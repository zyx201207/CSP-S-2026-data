#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define TIII tuple<int,int,int>
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define il inline
#define rg register
#define fi first
#define se second
#define MAXN 100005
using namespace std;
string c1,s1,c2,s2;
char s[10];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1 != c2) s[0] = s[1] = s[2] = s[3] = '0';
	else
	{
		s[0] = '1';
		if (s1[0] == s2[0] && s1[1] == s2[1]) 
		{
			s[1] = '1';
			if (((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) || ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))) 
			{
				s[2] = '1';
				if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'B'))) s[3] = '1';
				else s[3] = '0';
			}
			else s[2] = s[3] = '0';
		}
		else s[1] = s[2] = s[3] = '0';
	}
	for (rg int i = 0;i<4;i++) cout<<s[i];
	cout<<endl;
	return 0;
}
