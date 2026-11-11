#include<bits/stdc++.h>
using namespace std;

long long n, a, cnt;
char b;

string str;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		while(a--)
			str.push_back(b);
	}
	for(int i=0;i<(int)str.size() / 2;i++)
	{
		if(str[i] != str[(int)str.size()-i-1]) cnt++;
	}
	
	cout<<cnt;
	
}
