#include<bits/stdc++.h>
using namespace std;

stack<char>s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt = 0;
	cin >> n;
	string str;
	for(int i = 1;i <= n;i++)
	{
		int a;
		char c;
		cin >> a >> c;
		cnt+=a;
		while(a--)
		{
			s.push(c);
			str += c;
		}
	}
	int ans = 0;
	for(int i = 0;i < cnt/2;i++)
	{
		if(s.top() != str[i])
		{
			ans++;
		}
		s.pop();
	}
	cout<<ans;
	return 0;
} 
