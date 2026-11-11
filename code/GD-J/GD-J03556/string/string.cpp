#include <bits/stdc++.h>
using namespace std;
int n;
string s1,s2;
int check(string s,int cnt)
{
	string str;
	int g=s.size();
	for(int i=0; i<g; i++)
	{
		
		str[i]=s[g-i-1];
	}
	
	for(int i=0; i<(g+1)/2; i++)
	{
		if(s[i]!=str[i]) cnt++; 
	}
	return cnt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1,num; i<=n; i++)
	{
		char c;
		cin >> num;
		getchar();
		cin >> c;
		for(int j=0; j<num; j++)
		{
			s1+=c;
		}
	}
	cout << check(s1,0);
	return 0;
}
