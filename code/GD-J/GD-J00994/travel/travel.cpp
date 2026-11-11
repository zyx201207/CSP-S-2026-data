#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans1,ans2,ans3,ans4;
int p1,p2;
bool check()
{
	return !((s1[2] <= 'C') ^ (s2[2] <= 'C'));
}
bool check1()
{
	char a = s1[2],b = s2[2];
	if (a > b) swap(a,b);
	return b - a == 1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	p1 = (s1[0] - '0') * 10 + (s1[1] - '0'); 
	p2 = (s2[0] - '0') * 10 + (s2[1] - '0'); 
	ans1 = (c1 == c2);
	ans2 = (ans1 && (p1 == p2));
	ans3 = (ans1 && ans2 && check());
	ans4 = (ans1 && ans2 && ans3 && check1());
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}
