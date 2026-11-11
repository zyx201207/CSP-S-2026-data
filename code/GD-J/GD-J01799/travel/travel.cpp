#include <bits/stdc++.h>
using namespace std;
int check(char x)
{
	if('A' <= x && x <= 'C')return 1;
	return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string a,b,s,t;
	cin >> a >> b >> s >> t;
	string cnt1 = "",cnt2 = "";
	for(int i = 0;i < b.size() - 1;i++)cnt1 += b[i];
	for(int i = 0;i < t.size() - 1;i++)cnt2 += t[i];
	char tot = b[2],tot2 = t[2];
	if(a == s)cout << 1;
	else cout << 0;
	if(a == s && cnt1 == cnt2)cout << 1;
	else cout << 0;
	if(a == s && cnt1 == cnt2)
	{
		if(check(tot) == check(tot2))cout << 1;
		else cout << 0;
	}
	else cout << 0;
	if(a == s && cnt1 == cnt2)
	{
		if(check(tot) == check(tot2))
		{
			if(tot - 1 == tot2 || tot + 1 == tot2)cout << 1;
			else cout << 0;
		}
		else cout << 0;
	}
	else cout << 0;
	return 0;
}
