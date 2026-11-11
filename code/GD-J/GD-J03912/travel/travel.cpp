#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int f1=0,f2=0,f3=0,f4=0;
unordered_map<char, int> mp,bh;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin >> c1 >> s1 >> c2 >> s2;
	mp['A'] = mp['B'] = mp['C'] = 1;
	mp['D'] = mp['F'] = 2;
	bh['A'] = 1;
	bh['B'] = 2;
	bh['C'] = 3;
	bh['D'] = 100;
	bh['F'] = 101;
	if (c1 == c2)
	{
		f1 = 1;
	}
	if (f1 == 1 && s1[0] == s2[0] && s1[1] == s2[1])
	{
		f2 = 1;
	}
	if (f2 == 1 && mp[s1[2]] == mp[s2[2]])
	{
		f3 = 1;
	}
	if (f3 == 1 && abs(bh[s1[2]] - bh[s2[2]]) == 1)
	{
		f4 = 1;
	}
	cout <<f1 << f2 << f3 << f4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

