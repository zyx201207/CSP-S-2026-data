#include <bits/stdc++.h>
using namespace std;
struct str
{
	long long a;
	char c;
};
str s[2000005],t[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		cin >> s[i].a >> s[i].c;
		t[n+1-i].a=s[i].a;
		t[n+1-i].c=s[i].c;
	}
	long long cnt = 0,pss = 1,pst = 1;
	bool flag = s[1].a > s[n].a;
	while(pss<=n&&pst<=n)
	{
		if(s[pss].a>=t[pst].a)
		{
			if(s[pss].c!=t[pst].c)cnt+=t[pst].a;
			s[pss].a-=t[pst].a;
			t[pst].a=0;
			pst++;
		}
		else
		{
			if(s[pss].c!=t[pst].c)cnt+=s[pss].a;
			t[pst].a-=s[pss].a;
			s[pss].a=0;
			pss++;
		}
	}
	cout << cnt/2;
	return 0;
}
