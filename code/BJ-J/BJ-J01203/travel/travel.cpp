#include<bits/stdc++.h>
using namespace std;

string s1,s2,p1,p2,ans;
int c1,c2,r1,r2;

int toi(string p)
{
	int ans;
	if(p == "A") ans = 1;
	if(p == "B") ans = 2;
	if(p == "C") ans = 3;
	if(p == "D") ans = 4;
	if(p == "F") ans = 5;
	return ans;
}


int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>r1>>s1>>r2>>s2;
	p1 = s1.substr(0,2);
	p2 = s2.substr(0,2);
	c1 = toi(s1.substr(2,1));
	c2 = toi(s2.substr(2,1));
	if(r1 == r2)
		if(p1 == p2)
			if((c1 <= 3 && c2 <= 3 )|| (c1 > 3 && c2 > 3))
				if((c1 == c2+1) || (c1 == c2-1))
					ans = "1111";
				else 
					ans = "1110";
			else
				ans = "1100";
		else
			ans = "1000";
	else
		ans = "0000";
	cout<<ans;
	return 0;
}
