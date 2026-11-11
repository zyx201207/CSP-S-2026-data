//rp++ ak++ csp-j++ 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);//记得改回来 
	freopen("travel.out", "w", stdout); 
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "";
	if (c1 != c2) 
		ans += "0000";
	else 
	{
		ans += "1";
		int a = 0, b = 0, la = s1.size(), lb = s2.size();
		int A = (s1[la-1] - 'A') + 1, B = (s2[lb-1] - 'A') + 1; 
		for (int i = 0; i < la; i++) 
		{
			if (s1[i] >= '0' && s1[i] <= '9')
				a = a * 10 + (s1[i] - '0');
			else break;
		}
		for (int i = 0; i < lb; i++) 
		{
			if (s2[i] >= '0' && s2[i] <= '9')
				b = b * 10 + (s2[i] - '0');
			else break;
		}
		if (a != b) 
			ans += "00";
		else
		{
			ans += "1";
			if ((A <= 3 && B <= 3) || (A >= 4 && B >= 4))
				ans += "1"; 
			else ans += "0";
		}
		if (((abs(A-B) == 1 && a == b) || (abs(a-b) == 1 && A == B)) && (A <= 3 && B <= 3) || (A >= 4 && B >= 4))
			ans += "1";
		else 
			ans += "0";
	} 
	cout << ans << endl;
	return 0;
}
