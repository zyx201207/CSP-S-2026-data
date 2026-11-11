#include<bits/stdc++.h>
#define ll long long
#define ull long long
using namespace std;
int x;
string c1, s1, c2, s2;
bool f1, f2, f3, f4;
void solve()
{
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2) f1 = 1;;
	cout<<f1;
	if(f1 && s1[0] == s2[0] && s1[1] == s2[1]) f2 = 1;
	cout<<f2;
	if(f2 && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))) f3 = 1;
	cout<<f3;
	int x = abs(s1[2] - s2[2]);
	if(f3 && x == 1) f4 = 1;
	cout<<f4;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}

