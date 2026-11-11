#include <bits/stdc++.h>
using namespace std;
struct stu
{
	long long a;
	char c;
}s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> s[i].a >> s[i].c;
	int l = 1,r = 1,li = 1,ri = n;
	while(li <= ri)
	{
		if(s[li].c != s[ri].c)
		{
			if(s[li].a == s[ri].a)
			{
				ans += s[li].a;
				li++;
				ri--;
			}
			else if(s[li].a > s[ri].a)
			{
				ans += s[ri].a;
				s[li].a -= s[ri].a;
				ri--;
			}
			else if(s[li].a < s[ri].a)
			{
				ans += s[li].a;
				s[ri].a -= s[li].a;
				li++;
			}
		}
		else
		{
			if(s[li].a == s[ri].a)
			{
				li++;
				ri--;
			}
			else if(s[li].a > s[ri].a)
			{
				s[li].a -= s[ri].a;
				ri--;
			}
			else if(s[li].a < s[ri].a)
			{
				s[ri].a -= s[li].a;
				li++;
			}
		}
	}
	cout << ans;
	return 0;
}
