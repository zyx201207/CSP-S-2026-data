#include <bits/stdc++.h>
using namespace std;
string s[20000001];
int ans;
int v;
char e;
int n,t = 0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	while(n--)
	{
		cin >> v >> e;
		for(int i = t;i <= t+v-1;i++)
		{
			s[i] = e;
		}
		
		t+=v;
	}
	if(t % 2 == 1) t--;
	for(int i = 0;i <= t/2;i++)
	{
		if(s[i] != s[t-i]) ans++;	
	}
	cout << ans;
	return 0;
}
