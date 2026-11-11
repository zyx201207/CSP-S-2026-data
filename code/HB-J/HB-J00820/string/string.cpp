#include <bits/stdc++.h>
using namespace std;
long long a[100005],cnt,n;
char b[100005];
long long ans;
vector <char> s;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	scanf("%lld",&n);
	while(n--)
	{
		long long d;
		char c;
		scanf("%lld",&d);
		scanf("%s",&c);
		for(int i=1;i<=d;i++)
			s.push_back(c);
	}
	int h=0,t=s.size()-1;
	while(h<t)
	{
		if(s[h]!=s[t])
		{
			cnt++;
		}
		h++;
		t--;
	}
	cout<<cnt;
	return 0;
}
